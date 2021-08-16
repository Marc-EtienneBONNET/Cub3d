/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_d_perso(t_vecteur perso, t_vecteur *d_perso, float ray)
{
	int	tmp_x;
	int	tmp_y;

	d_perso->x = perso.x;
	d_perso->y = perso.y;
	while (d_perso->x >= 1)
		d_perso->x--;
	while (d_perso->y >= 1)
		d_perso->y--;
	if (ray > 180)
	{
		tmp_y = (int)(perso.y + 1);
		d_perso->y = (float)(((float)tmp_y) - perso.y);
	}
	if (ray < 90 || ray > 270)
	{
		tmp_x = (int)(perso.x + 1);
		d_perso->x = (float)(((float)tmp_x) - perso.x);
	}
}

float	ft_init_angle(float vue)
{
	float	res;

	if (vue >= 0 && vue <= 90)
		res = vue;
	if (vue > 90 && vue <= 180)
		res = 180 - vue;
	if (vue > 180 && vue <= 270)
		res = vue - 180;
	if (vue > 270 && vue <= 360)
		res = 360 - vue;
	return (res);
}

int	ft_mouv_raycasting(t_parsage *pars, t_search_cub *search)
{
	if (pars->mouv.cam_droite == 124)
		ft_cam_rot(pars, 124);
	if (pars->mouv.cam_gauche == 123)
		ft_cam_rot(pars, 123);
	if (pars->mouv.avant == 12)
		ft_calcule_vecteur_mouv(pars, pars->ray.avant);
	if (pars->mouv.arriere == 6)
		ft_calcule_vecteur_mouv(pars, pars->ray.arriere);
	if (pars->mouv.gauche == 2)
		ft_calcule_vecteur_mouv(pars, pars->ray.droite);
	if (pars->mouv.droite == 1)
		ft_calcule_vecteur_mouv(pars, pars->ray.gauche);
	if (pars->mouv.sup == 53)
		ft_close_programe(pars);
	ft_ajust_ray(&(pars->ray.avant));
	ft_init_autre_ray(pars);
	search->perso = pars->perso;
	ft_init_d_perso(pars->perso, &(search->d_perso), pars->ray.debut_vue);
	search->map = pars->map;
	search->ray = pars->ray.debut_vue;
	new_image(pars);
	search->avant = pars->ray.avant;
	return (1);
}

int	ft_protocol_raycasting(t_parsage *pars)
{
	t_search_cub	search;
	int				x;
	float			tmp;

	x = 0;
	ft_mouv_raycasting(pars, &search);
	while (x < pars->reso.x)
	{
		ft_init_d_perso(pars->perso, &(search.d_perso), search.ray);
		search.angle = ft_init_angle(search.ray);
		ft_search_cub(&search);
		if (search.ray >= pars->ray.avant)
			tmp = ft_absolut_2(pars->ray.avant - search.ray);
		else
			tmp = ft_absolut_2(pars->ray.avant - search.ray);
		search.res.d *= cosf(tmp * (PI / 180));
		ft_drow_cub(*pars, x, search);
		search.ray -= pars->ray.op_ray;
		ft_ajust_ray(&(search.ray));
		x++;
	}
	ft_init_ray_dist_trie(pars, pars->perso);
	mlx_put_image_to_window(pars->mlx.mlx, pars->mlx.window,
		pars->mlx.img.struct_img, 0, 0);
	return (1);
}
