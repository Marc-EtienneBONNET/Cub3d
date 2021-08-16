/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_dernier_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_verif_cara(char *str, char cara)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == cara)
			return (1);
		x++;
	}
	return (-1);
}

int	ft_verif_line(char *line, char *str)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (ft_verif_cara(str, line[x]) == -1)
			return (-1);
		x++;
	}
	if (x == 0)
		return (2);
	return (1);
}

int	ft_verif_dernier_line_info_cub(char *lien)
{
	int		fd;
	char	*line;
	int		x;
	int		test;

	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	x = get_next_line(fd, &line);
	test = ft_verif_line(line, "012NSEW ");
	while (x > 0 && (test == -1 || test == 2))
	{
		free(line);
		x = get_next_line(fd, &line);
	}
	while (ft_verif_line(line, "012NSEW ") == 1)
	{
		free(line);
		x = get_next_line(fd, &line);
	}
	if (ft_verif_line(line, "    ") == -1)
		return (ft_fonction_fermeture_free(fd, line, -1));
	return (ft_fonction_fermeture_free(fd, line, 1));
}
