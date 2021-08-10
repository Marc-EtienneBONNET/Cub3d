/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:36:34 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:55:44 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mlx_pixel_get_2(t_tex texture, int x, int y, t_parsage pars)
{
	int	color;
	int	*data_int;

	data_int = (int *)texture.data;
	color = data_int[y * pars.reso.x + (int)(x)];
	return (color);
}

int	ft_verif_cub_devant(t_obj obj, t_parsage pars, int x)
{
	int		color;
	int		y;
	int		conteur;
	t_tex	tmp;

	tmp.img_ptr = pars.mlx.img.struct_img;
	tmp.data = pars.mlx.img.adr;
	tmp.endian = pars.mlx.img.endian;
	tmp.bpp = pars.mlx.img.bitp;
	tmp.taille_line = pars.mlx.img.linelength;
	conteur = 0;
	y = 0;
	while (y < pars.reso.y)
	{
		color = ft_mlx_pixel_get_2(tmp, ((int)(x + obj.pos_x)), ((int)y), pars);
		if (color != pars.decor.c && color != pars.decor.t)
			conteur++;
		y++;
	}
	return (conteur);
}

int	ft_init_my_draw_pixel_2(t_parsage pars, t_obj *obj, float x)
{
	float	y;
	int		color;

	y = 0;
	if (x + obj->pos_x > pars.reso.x)
		return (0);
	else if (x + obj->pos_x < 0)
		return (1);
	else if (ft_verif_cub_devant(*obj, pars, x) > (int)(obj->taille_y))
		return (1);
	while (y < obj->taille_y)
	{
		obj->coef_y = y / obj->taille_y;
		color = ft_mlx_pixel_get(pars.lst_texture[0],
				((int)(obj->coef_x * pars.lst_texture[0].taille_x)),
				((int)(obj->coef_y * pars.lst_texture[0].taille_y)));
		if (color > 0 && y + (pars.reso.y - obj->taille_y) / 2 < pars.reso.y)
		{
			my_mlx_pixel_put(&(pars.mlx.img), x + obj->pos_x,
				y + (pars.reso.y - obj->taille_y) / 2, color);
		}
		y++;
	}
	return (1);
}

void	ft_init_drow_obj(t_parsage pars, t_obj *obj)
{
	float	x;
	int		w;

	w = 0;
	while (obj[w].x != -1)
	{
		x = 0;
		while (x < obj[w].taille_x)
		{
			obj[w].coef_x = x / obj[w].taille_x;
			if (ft_init_my_draw_pixel_2(pars, &(obj[w]), x) == 0)
				break ;
			x++;
		}
		w++;
	}
}
