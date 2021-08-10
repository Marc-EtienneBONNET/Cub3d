/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mouv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:10:09 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:55:32 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cam_rot(t_parsage *pars, int key)
{
	if (key == 123)
		pars->ray.avant += 4;
	else if (key == 124)
		pars->ray.avant -= 4;
}

void	ft_mouv_pos(t_vecteur mouv, float ray, t_vecteur *perso)
{
	int	op_x;
	int	op_y;

	op_x = -1;
	op_y = -1;
	if ((ray >= 0 && ray < 90) || (ray <= 360 && ray > 270))
		op_x = 1;
	if ((ray <= 270 && ray > 180) || (ray >= 270 && ray < 360))
		op_y = 1;
	perso->x += ((mouv.x + 0.000001) * op_x);
	perso->y += ((mouv.y + 0.000001) * op_y);
}

void	ft_calcul_deplacement(float multiple, float angle, t_vecteur *v)
{
	v->x = cosf(angle * (PI / 180)) * multiple;
	v->y = sinf(angle * (PI / 180)) * multiple;
}

void	ft_calcule_vecteur_mouv(t_parsage *pars, float ray)
{
	t_vecteur	v;
	t_vecteur	test;

	test = pars->perso;
	ft_calcul_deplacement(0.1, ft_init_angle(ray), &v);
	ft_mouv_pos(v, ray, &(test));
	if (pars->map[(int)test.y][(int)test.x] != '1'
	&& pars->map[(int)test.y][(int)test.x] != '2')
	{
		ft_calcul_deplacement(0.1, ft_init_angle(ray), &v);
		ft_mouv_pos(v, ray, &(pars->perso));
	}
}
