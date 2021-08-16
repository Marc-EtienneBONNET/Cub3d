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

#include "cub3d.h"

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
		return (ft_fonction_fermeture_free(fd, line, -1));
	return (ft_fonction_fermeture_free(fd, line, 1));
}
