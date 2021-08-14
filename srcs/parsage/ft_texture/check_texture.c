/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_verif_nb_para_texture(char *lien, char *para)
{
	int		fd;
	char	*line;
	int		x;
	int		conteur;

	conteur = 0;
	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		while (line[x] == ' ')
			x++;
		if ((line[x] == para[0] && line[x + 1] == para[1] && !(para[2])) 
			|| (para[2] && line[x] == para[0] && line[x + 1] == para[1] 
			&& line[x + 2] == para[2]))
			conteur++;
		free(line);
	}
	if (conteur != 1)
		return (ft_fonction_fermeture_free(fd, &line, -1));
	return (ft_fonction_fermeture_free(fd, &line, 1));
}

void	ft_protocole_verif_format_1(char *line, int *x, int *verif)
{
	while (line[*x] != '\0')
		(*x)++;
	if (line[(*x) - 1] == 'm' && line[(*x) - 2] == 'p'
		&& line[(*x) - 3] == 'x' && line[(*x) - 4] == '.')
		*verif = 1;
}

int	ft_verif_format_texture(char *lien, char *para)
{
	int		fd;
	char	*line;
	int		x;
	int		verif;

	verif = -1;
	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		while (line[x] == ' ')
			x++;
		if (line[x] == para[0] && line[x + 1] == para[1])
			ft_protocole_verif_format_1(line, &x, &verif);
		free(line);
	}
	return (ft_fonction_fermeture_free(fd, &line, verif));
}

int	ft_init_verif_texture(char *lien)
{
	if (ft_verif_nb_para_texture(lien, "NO ") < 0
		|| ft_verif_nb_para_texture(lien, "SO ") < 0
		|| ft_verif_nb_para_texture(lien, "EA ") < 0
		|| ft_verif_nb_para_texture(lien, "WE ") < 0
		|| ft_verif_nb_para_texture(lien, "S ") < 0)
		return (-1);
	if (ft_verif_format_texture(lien, "NO ") < 0
		||ft_verif_format_texture(lien, "SO ") < 0
		||ft_verif_format_texture(lien, "EA ") < 0
		||ft_verif_format_texture(lien, "WE ") < 0
		||ft_verif_format_texture(lien, "S ") < 0)
		return (-1);
	return (1);
}
