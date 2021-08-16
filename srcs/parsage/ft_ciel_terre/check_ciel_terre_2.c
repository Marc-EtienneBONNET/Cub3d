/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ciel_terre_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_protocole_recup(char *line, int *x, int *rgb)
{
	int	index;

	index = 0;
	(*x)++;
	while (line[*x] != '\0')
	{
		while (line[*x] == ' ')
			(*x)++;
		rgb[index] = atoi(&(line[*x]));
		while ((line[*x] >= '0' && line[*x] <= '9') || line[*x] == ' ')
			(*x)++;
		if (line[*x] == ',')
			(*x)++;
		index++;
	}
}

void	ft_protocole_compte_nb(char *line, int *conteur, char para)
{
	int	x;

	x = 0;
	while (line[x] == ' ')
		x++;
	if (line[x] == para)
	{
		x++;
		while (line[x] != '\0')
		{
			while (line[x] == ' ')
				x++;
			if (line[x] >= '0' && line[x] <= '9')
			{
				(*conteur)++;
				while ((line[x] >= '0' && line[x] <= '9') || line[x] == ' ')
					x++;
			}
			if (*conteur == 3 && line[x] != '\0')
				*conteur = -1;
			if (line[x] == ',')
				x++;
		}
	}
}

int	ft_verif_nb_nombre(char *lien, char para)
{
	int		fd;
	char	*line;
	int		conteur;

	conteur = 0;
	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	while (get_next_line(fd, &line) > 0)
	{
		ft_protocole_compte_nb(line, &conteur, para);
		free(line);
	}
	if (conteur != 3)
		return (ft_fonction_fermeture_free(fd, line, -1));
	return (ft_fonction_fermeture_free(fd, line, 1));
}

int	ft_verif_cara_c_f(char *lien, char para)
{
	int		fd;
	char	*line;
	int		x;
	int		verif;

	verif = 1;
	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		while (line[x] == ' ')
			x++;
		if (line[x] == para)
			while (line[++x] != '\0')
				if ((line[x] < '0' || line[x] > '9')
					&& line[x] != ' ' && line[x] != ',')
					verif = -1;
		free(line);
	}
	return (ft_fonction_fermeture_free(fd, line, verif));
}
