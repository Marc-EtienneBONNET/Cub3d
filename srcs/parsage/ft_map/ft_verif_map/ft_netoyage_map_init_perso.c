/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_netoyage_map_init_perso.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:32:05 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:57:53 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3d.h"

void	ft_netoyage(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][0] != '\0')
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'X')
				map[y][x] = '0';
			else if (map[y][x] == 'x')
				map[y][x] = '2';
			x++;
		}
		y++;
		x = 0;
	}
}

int	ft_rempli_perso(t_parsage *pars, t_tmp *test, char **map, int conteur)
{
	if (conteur != 1 || map[test->y][test->x + 1] == '\0' || test->x == 0
	|| map[test->y][0] == '\0' || test->y == 0)
		return (-1);
	pars->perso.x = (float)(test->x + 0.5);
	pars->perso.y = (float)(test->y + 0.5);
	pars->perso.t = map[test->y][test->x];
	return (1);
}

void	ft_recherche_perso_2(char **map, t_tmp *test, int *y, int *conteur)
{
	int	x;

	x = 0;
	while (map[*y][x] != '\0')
	{
		if (map[*y][x] == 'N' || map[*y][x] == 'S'
			|| map[*y][x] == 'W' || map[*y][x] == 'E')
		{
			test->x = x;
			test->y = *y;
			(*conteur)++;
		}
		x++;
	}
	(*y)++;
}

int	ft_recherche_perso(char **map, t_tmp *test, t_parsage *pars)
{
	int	x;
	int	y;
	int	conteur;

	x = 0;
	y = 0;
	conteur = 0;
	while (map[y][0] != '\0')
		ft_recherche_perso_2(map, test, &y, &conteur);
	if (conteur != 1)
		return (-1);
	return (ft_rempli_perso(pars, test, map, conteur));
}

void	ft_rempli_case_centre(t_parsage *pars, t_tmp test2, int *res, t_tmp2 a)
{
	test2.x = a.x;
	test2.y = a.y;
	ft_test(pars, test2, res);
}
