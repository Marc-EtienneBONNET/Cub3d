/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:51:31 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:40 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calcul_ad(float angle, t_vecteur *v, float multiple)
{
	if (angle == 90)
	{
		v->y = multiple;
		v->x = 0;
	}
	else if (angle == 0)
	{
		v->y = 0;
		v->x = multiple;
	}
	else
	{
		v->x = multiple / tanf(angle * (PI / 180));
		v->y = multiple;
	}
	v->d = sqrtf((v->x * v->x) + (v->y * v->y));
}

void	ft_calcul_op(float angle, t_vecteur *h, float multiple)
{
	if (angle == 90)
	{
		h->y = multiple;
		h->x = 0;
	}
	else if (angle == 0)
	{
		h->x = multiple;
		h->y = 0;
	}
	else
	{
		h->y = (tanf(angle * (PI / 180))) * multiple;
		h->x = multiple;
	}
	h->d = sqrtf((h->x * h->x) + (h->y * h->y));
}

void	ft_fusion_vecteur_perso(t_vecteur *v, t_vecteur *h,
float ray, t_vecteur perso)
{
	int	op_x;
	int	op_y;

	op_x = -1;
	op_y = -1;
	if ((ray >= 0 && ray < 90) || (ray <= 360 && ray > 270))
		op_x = 1;
	if ((ray <= 270 && ray > 180) || (ray >= 270 && ray < 360))
		op_y = 1;
	v->x = perso.x + ((v->x + 0.001) * op_x);
	v->y = perso.y + (v->y * op_y);
	h->x = perso.x + (h->x * op_x);
	h->y = perso.y + ((h->y + 0.001) * op_y);
}

float	ft_calcul_x(float x)
{
	while (x > 1)
		x--;
	return (x);
}

void	ft_search_cub(t_search_cub *search)
{
	t_vecteur	v;
	t_vecteur	h;

	ft_calcul_search_res(search, &v, &h);
	while (search->map[(int)(search->res.y)][(int)(search->res.x)] != '1'
	&& search->map[(int)(search->res.y)][(int)(search->res.x)] != '\0')
		ft_calcul_search_res(search, &v, &h);
}
