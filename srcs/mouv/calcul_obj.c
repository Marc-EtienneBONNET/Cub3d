/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:33:31 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:55:12 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_calcul_pos_x(t_parsage *pars, t_obj *obj)
{
	float	tmp;
	int		multiple;
	int		x;

	multiple = 1;
	x = 0;
	tmp = obj->ray - pars->ray.avant;
	ft_ajust_ray(&tmp);
	if (tmp <= 180)
		multiple = -1;
	while ((int)tmp != 0)
	{
		tmp += pars->ray.op_ray * multiple;
		ft_ajust_ray(&tmp);
		x++;
	}
	obj->pos_x = pars->reso.x / 2 + (x * multiple - obj->taille_x / 2);
}

void	ft_taille_obj(t_parsage *pars)
{
	int	x;

	x = 0;
	while (pars->obj[x].x != -1)
	{
		pars->obj[x].taille_y = pars->cub_y / pars->obj[x].d;
		pars->obj[x].taille_x = pars->lst_texture[0].taille_x
			* (pars->obj[x].taille_y / pars->lst_texture[0].taille_y);
		pars->obj[x].coef_x = pars->lst_texture[0].taille_x
			/ pars->obj[x].taille_x;
		pars->obj[x].coef_y = pars->lst_texture[0].taille_y
			/ pars->obj[x].taille_y;
		ft_calcul_pos_x(pars, &(pars->obj[x]));
		x++;
	}
}

void	ft_init_ray_dist_trie(t_parsage *pars, t_vecteur perso)
{
	float	x;
	int		w;
	float	y;

	w = 0;
	while (pars->obj[w].x != -1)
	{
		x = ft_absolut_2(pars->obj[w].x - perso.x);
		y = ft_absolut_2(pars->obj[w].y - perso.y);
		pars->obj[w].d = sqrtf((x * x) + (y * y));
		ft_calcul_ray(y, &(pars->obj[w]), perso);
		if (pars->obj[w].ray < pars->ray.avant
			+ ANGLE_VUE / 2 + 10 && pars->obj[w].ray
			> pars->ray.avant - (ANGLE_VUE / 2 + 10))
		{
			pars->obj[w].d *= cosf(ft_absolut_2(pars->ray.avant
						- pars->obj[w].ray) * (PI / 180));
		}
		w++;
	}
	ft_trie_tab(pars->obj);
	ft_taille_obj(pars);
	ft_init_drow_obj(*pars, pars->obj);
}
