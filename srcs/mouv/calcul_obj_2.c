/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_obj_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:14:25 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:55:22 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	ft_absolut_2(float x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	ft_trie_tab(t_obj *obj)
{
	int		x;
	int		y;
	t_obj	tmp;

	x = 1;
	y = 0;
	while (obj[y].x != -1)
	{
		while (obj[x].x != -1)
		{
			if (obj[x - 1].d < obj[x].d)
			{
				tmp = obj[x - 1];
				obj[x - 1] = obj[x];
				obj[x] = tmp;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	ft_calcul_ray(float y, t_obj *obj, t_vecteur perso)
{
	obj->angle = asinf(y / obj->d) / (PI / 180);
	if (perso.x <= obj->x && perso.y >= obj->y)
		obj->ray = obj->angle;
	else if (perso.x >= obj->x && perso.y >= obj->y)
		obj->ray = 180 - obj->angle;
	else if (perso.x >= obj->x && perso.y <= obj->y)
		obj->ray = 180 + obj->angle;
	else if (perso.x <= obj->x && perso.y <= obj->y)
		obj->ray = 360 - obj->angle;
}
