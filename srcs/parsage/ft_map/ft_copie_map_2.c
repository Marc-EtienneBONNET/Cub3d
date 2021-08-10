/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copie_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_free(t_parsage *pars, int x, int taille)
{
	free(&(pars->map[taille]));
	while (x >= 0)
		free(&(pars->map[--x]));
	free(pars->map);
	return (-1);
}

int	ft_verif_nb(int fd)
{
	char	*line;
	int		test;

	line = NULL;
	test = get_next_line(fd, &line);
	while (test >= 0)
	{
		if (ft_verif_line(line, "012 NSEW") == 1)
		{
			free(line);
			free(line);
			return (-1);
		}
		else if (test == 0)
			break ;
		free(line);
		test = get_next_line(fd, &line);
	}
	free(line);
	return (1);
}

int	ft_copie_line(char *map, char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == ' ')
			map[x] = '1';
		else
			map[x] = line[x];
		x++;
	}
	map[x] = '\0';
	return (1);
}
