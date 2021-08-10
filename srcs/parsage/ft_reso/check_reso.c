/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_protocole_verif_nombre(char *line, int *conteur)
{
	int	x;

	x = 0;
	while (line[x] == ' ')
		x++;
	if (line[x++] == 'R')
	{
		while (line[x] != '\0' && ((line[x] >= '0' && line[x] <= '9')
				|| line[x] == ' '))
		{
			if ((line[x] < '0' || line[x] > '9') && line[x] != ' ')
				return (-1);
			while (line[x] == ' ')
				x++;
			if (line[x] >= '0' && line[x] <= '9')
			{
				(*conteur)++;
				while (line[x] >= '0' && line[x] <= '9')
					x++;
			}
		}
		if (ft_verif_line(line, "R 0123456789") != 1)
			return (-1);
	}
	return (1);
}

int	ft_verif_nombre(char *lien)
{
	int		fd;
	char	*line;
	int		conteur;

	conteur = 0;
	line = NULL;
	fd = open(lien, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_protocole_verif_nombre(line, &conteur) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (conteur != 2)
		return (ft_fonction_fermeture_free(fd, line, -1));
	return (ft_fonction_fermeture_free(fd, line, 1));
}

void	ft_protocole_memorise(char *line, t_parsage *pars)
{
	int	x;

	x = 0;
	while (line[x] == ' ')
		x++;
	if (line[x] == 'R')
	{
		x++;
		while (line[x] == ' ')
			x++;
		pars->reso.x = ft_atoi(&(line[x]));
		while (line[x] >= '0' && line[x] <= '9')
			x++;
		pars->reso.y = ft_atoi(&(line[x]));
	}
}

int	ft_memorise_nb_reso(t_parsage *pars, char *lien)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(lien, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_protocole_memorise(line, pars);
		free(line);
	}
	return (ft_fonction_fermeture_free(fd, line, 1));
}

int	ft_init_recup_reso(t_parsage *pars, char *lien)
{
	if (ft_verif_nb_para(lien, 'R') < 0)
		return (-1);
	if (ft_verif_nombre(lien) < 0)
		return (-2);
	if (ft_memorise_nb_reso(pars, lien) < 0)
		return (-3);
	if (pars->reso.x <= 0 || pars->reso.y <= 0)
		return (-4);
	return (1);
}
