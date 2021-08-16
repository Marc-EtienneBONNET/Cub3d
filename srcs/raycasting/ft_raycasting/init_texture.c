/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:51:10 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:21 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adr + (y * data->linelength + x * (data->bitp / 8));
	*(unsigned int *)dst = color;
}

int	ft_choose_color(t_parsage pars, t_search_cub search)
{
	if (search.res.t == 'v')
	{
		if (pars.perso.x < search.res.x)
			return (3);
		else
			return (4);
	}
	else if (search.res.t == 'h')
	{
		if (pars.perso.y < search.res.y)
			return (1);
		else
			return (2);
	}
	return (-1);
}

int	ft_mlx_pixel_get(t_tex texture, int x, int y)
{
	int	color;
	int	*data_int;

	data_int = (int *)texture.data;
	color = data_int[y * texture.taille_x + (int)(x)];
	return (color);
}

t_vecteur	ft_recup_coef(t_vecteur res, int y, int debut, int taille)
{
	t_vecteur	coef;

	while (res.x > 1)
		res.x--;
	coef.x = (float)(res.x / 1);
	if (res.t == 'v')
	{
		while (res.y > 1)
			res.y--;
		coef.x = (float)(res.y / 1);
	}
	coef.y = (float)((float)(y - debut) / (float)(taille));
	return (coef);
}
