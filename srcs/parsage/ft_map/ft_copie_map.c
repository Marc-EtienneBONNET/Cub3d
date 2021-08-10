/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:21:06 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:57:27 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_init_copie(t_parsage *pars, char *line, int *w, int taille)
{
	int	x;

	x = 0;
	if (ft_verif_line(line, "012NSEW ") == 1)
	{
		while (line[x] != '\0')
			x++;
		pars->map[*w] = (char *)malloc(sizeof(char) * (x + 1));
		if (!(pars->map[*w]))
			return (ft_free(pars, *w, taille));
		ft_copie_line(pars->map[*w], line);
		*w += 1;
	}
	return (1);
}

int	ft_init_map(t_parsage *pars, int taille, int fd, int *w)
{
	char	*line;

	line = NULL;
	pars->map = (char **)malloc(sizeof(char *) * (taille + 1));
	if (!(pars->map))
		return (-1);
	while (get_next_line(fd, &line) > 0 && ft_verif_line(line, "012 NSEW") != 1)
		free(line);
	if (ft_verif_line(line, "012NSEW ") == 1)
		ft_init_copie(pars, line, w, taille);
	free(line);
	while (get_next_line(fd, &line) > 0 && line[0] != '\0')
	{
		if (ft_init_copie(pars, line, w, taille) == 0)
			return (1);
		free(line);
	}
	ft_init_copie(pars, line, w, taille);
	free(line);
	pars->map[*w] = (char *)malloc(sizeof(char) * 1);
	if (!(pars->map[*w]))
		return (ft_free(pars, *w, taille));
	pars->map[*w][0] = '\0';
	return (1);
}

int	ft_trouve_map(int fd)
{
	char	*line;
	int		x;

	x = 1;
	line = NULL;
	while (get_next_line(fd, &line) > 0 && ft_verif_line(line, "012 NSEW") != 1)
		free(line);
	while (ft_verif_line(line, "012 NSEW") == 1)
	{
		x++;
		free(line);
		if (get_next_line(fd, &line) <= 0)
			break ;
	}
	free(line);
	if (ft_verif_nb(fd) == -1)
		return (-1);
	return (x);
}

int	ft_verif_dernier_line_map(t_parsage *pars)
{
	int	x;

	x = 0;
	while (pars->map[x][0] != '\0')
		x++;
	x--;
	if (ft_verif_line(pars->map[x], "1 ") != 1)
		return (-1);
	return (1);
}

int	ft_recup_map(t_parsage *pars)
{
	int	fd;
	int	res;
	int	w;

	w = 0;
	fd = open(pars->lien, O_RDONLY);
	res = ft_trouve_map(fd);
	if (res < 3)
		return (-1);
	close(fd);
	fd = open(pars->lien, O_RDONLY);
	ft_init_map(pars, res, fd, &w);
	if (ft_verif_dernier_line_map(pars) == -1)
		return (-1);
	close(fd);
	return (1);
}
