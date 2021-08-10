/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:08:02 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:57:17 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_init_ray_avant(t_parsage *pars)
{
	if (pars->perso.t == 'N')
		pars->ray.avant = 90;
	else if (pars->perso.t == 'S')
		pars->ray.avant = 270;
	else if (pars->perso.t == 'E')
		pars->ray.avant = 0;
	else if (pars->perso.t == 'W')
		pars->ray.avant = 180;
}

void	ft_ajust_ray(float *ray)
{
	if (*ray < 0)
		*ray = 360 + *ray;
	if (*ray > 360)
		*ray -= 360;
}

void	ft_init_autre_ray(t_parsage *pars)
{
	pars->ray.arriere = pars->ray.avant - 180;
	pars->ray.droite = pars->ray.avant - 90;
	pars->ray.gauche = pars->ray.avant + 90;
	pars->ray.debut_vue = pars->ray.avant + ANGLE_VUE / 2;
	pars->ray.op_ray = (float)ANGLE_VUE / (float)pars->reso.x;
	ft_ajust_ray(&(pars->ray.arriere));
	ft_ajust_ray(&(pars->ray.droite));
	ft_ajust_ray(&(pars->ray.gauche));
	ft_ajust_ray(&(pars->ray.debut_vue));
}

void	ft_init_ray(t_parsage *pars)
{
	ft_init_ray_avant(pars);
	ft_init_autre_ray(pars);
	pars->cub_y = (pars->reso.x * 580) / 600;
}
