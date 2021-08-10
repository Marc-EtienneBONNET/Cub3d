/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:23:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:56:18 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_compte(t_parsage *pars)
{
	int	x;
	int	y;
	int	w;

	x = 0;
	y = 0;
	w = 0;
	while (pars->map[y][x] != '\0')
	{
		while (pars->map[y][x] != '\0')
		{
			if (pars->map[y][x] == '2')
			{
				w++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (w);
}

int	ft_malloc_obj(t_parsage *pars)
{
	int	w;

	w = ft_compte(pars);
	if (w == 0)
	{
		pars->obj = (t_obj *)malloc(sizeof(t_obj) * (1));
		if (!(pars->obj))
			return (-1);
		pars->obj[0].x = -1;
		return (0);
	}
	pars->obj = (t_obj *)malloc(sizeof(t_obj) * (w + 1));
	if (!(pars->obj))
		return (-1);
	return (1);
}

int	ft_init_val(t_parsage *pars)
{
	int	x;
	int	y;
	int	w;

	y = 0;
	w = 0;
	x = 0;
	while (pars->map[y][x] != '\0')
	{
		while (pars->map[y][x] != '\0')
		{
			if (pars->map[y][x] == '2')
			{
				pars->obj[w].x = (float)(x + 0.5);
				pars->obj[w].y = (float)(y + 0.5);
				w++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	pars->obj[w].x = -1;
	return (1);
}

int	ft_init_obj(t_parsage *pars)
{
	int	x;
	int	y;
	int	w;

	y = 0;
	w = 0;
	x = ft_malloc_obj(pars);
	if (x == -1)
		return (-1);
	else if (x == 0)
		return (1);
	x = 0;
	ft_init_val(pars);
	return (1);
}
