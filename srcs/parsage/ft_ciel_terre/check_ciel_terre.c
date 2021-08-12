/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ciel_terre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_protocole_recup_ciel_terre(char *line, char para, int *res)
{
	int	rgb[3];
	int	x;

	x = 0;
	while (line[x] == ' ')
		x++;
	if (line[x] == para)
	{
		ft_protocole_recup(line, &x, rgb);
		if ((rgb[0] < 0 || rgb[0] > 255)
			|| (rgb[1] < 0 || rgb[1] > 255)
			|| (rgb[2] < 0 || rgb[2] > 255))
					return (-1);
		*res = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	}
	return (1);
}

int	ft_memorise_ciel_terre(t_parsage *pars, char *lien, char para, int choose)
{
	int		fd;
	char	*line;
	int		res;

	line = NULL;
	fd = open(lien, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_protocole_recup_ciel_terre(line, para, &res) == -1)
			res = -1;
		free(line);
	}
	if (choose == 1)
		pars->decor.c = res;
	else
		pars->decor.t = res;
	return (ft_fonction_fermeture_free(fd, line, res));
}

int	ft_protocole_verif_format(char *line, int *x)
{
	int	y;

	(*x)++;
	y = 0;
	while (y < 3)
	{
		while (line[*x] == ' ')
			(*x)++;
		if (line[*x] < '0' || line[*x] > '9')
			return (-1);
		while (line[*x] == ' ' || (line[*x] >= '0' && line[*x] <= '9'))
			(*x)++;
		if (line[*x] != ',' && line[*x] != '\0')
			return (-1);
		(*x)++;
		y++;
	}
	return (1);
}

int	ft_verif_format(char *lien, char para)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	line = NULL;
	fd = open(lien, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		y = 0;
		while (line[x] == ' ')
			x++;
		if (line[x] == para)
			y = ft_protocole_verif_format(line, &x);
		if (y < 0)
			return (ft_fonction_fermeture_free(fd, line, -1));
		else
			free(line);
	}
	return (ft_fonction_fermeture_free(fd, line, 1));
}

int	ft_init_recup_ciel_terre(t_parsage *pars, char *lien)
{
	if (ft_verif_nb_para(lien, 'C') < 0 || ft_verif_nb_para(lien, 'F') < 0)
		return (-1);
	if (ft_verif_cara_C_F(lien, 'C') < 0 || ft_verif_cara_C_F(lien, 'F') < 0)
		return (-2);
	if (ft_verif_format(lien, 'C') < 0 || ft_verif_format(lien, 'F') < 0)
		return (-3);
	if (ft_verif_nb_nombre(lien, 'C') < 0 || ft_verif_nb_nombre(lien, 'F') < 0)
		return (-4);
	if (ft_memorise_ciel_terre(pars, lien, 'C', 1) < 0
		|| ft_memorise_ciel_terre(pars, lien, 'F', 2) < 0)
		return (-5);
	return (1);
}
