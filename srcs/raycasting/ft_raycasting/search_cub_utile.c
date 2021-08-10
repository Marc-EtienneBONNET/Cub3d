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

#include "../../../includes/cub3d.h"

void	ft_calcul_search_res(t_search_cub *search, t_vecteur *v, t_vecteur *h)
{
	ft_calcul_ad(search->angle, h, search->d_perso.y);
	ft_calcul_op(search->angle, v, search->d_perso.x);
	ft_fusion_vecteur_perso(v, h, search->ray, search->perso);
	if (h->d > v->d)
	{
		search->d_perso.x += 1;
		search->res = *v;
		search->res.t = 'v';
	}
	else
	{
		search->d_perso.y += 1;
		search->res = *h;
		search->res.t = 'h';
	}
}
