/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:53:02 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:54:35 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mouv_raycasting_bmp(t_parsage *pars, t_search_cub *search)
{
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

int	ft_protocol_raycasting_bmp(t_parsage *pars)
{
	t_search_cub	search;
	int				x;
	float			tmp;

	x = 0;
	ft_mouv_raycasting_bmp(pars, &search);
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
