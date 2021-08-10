/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_and_init_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:00:55 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:14 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	new_image(t_parsage *pars)
{
	if (pars->mlx.img.struct_img)
		mlx_destroy_image(pars->mlx.mlx, pars->mlx.img.struct_img);
	pars->mlx.img.struct_img = mlx_new_image(pars->mlx.mlx, pars->reso.x,
			pars->reso.y);
	pars->mlx.img.adr = mlx_get_data_addr(pars->mlx.img.struct_img,
			&pars->mlx.img.bitp, &pars->mlx.img.linelength,
			&pars->mlx.img.endian);
	return (1);
}

void	ft_init_my_draw_pixel(t_search_cub search, t_vecteur para,
			t_vecteur pos, t_parsage pars)
{
	while (pos.y < pars.reso.y)
	{
		if (pos.y <= para.y)
			my_mlx_pixel_put(&(pars.mlx.img), pos.x, pos.y, pars.decor.c);
		else if (pos.y >= para.y && pos.y <= (para.x + para.y - 2))
		{
			search.coef = ft_recup_coef(search.res, pos.y, para.y, para.x);
			my_mlx_pixel_put(&(pars.mlx.img), pos.x, pos.y, ft_mlx_pixel_get(
					search.texture, (search.coef.x * search.texture.taille_x),
					(search.coef.y * search.texture.taille_y)));
		}
		else
			my_mlx_pixel_put(&(pars.mlx.img), pos.x, pos.y, pars.decor.t);
		pos.y++;
	}
}

void	ft_drow_cub(t_parsage pars, int x, t_search_cub search)
{
	t_vecteur	pos;
	t_vecteur	para;

	pos.x = (float)x;
	pos.y = 0;
	search.texture = pars.lst_texture[ft_choose_color(pars, search)];
	para.x = pars.cub_y / search.res.d;
	para.y = (pars.reso.y - para.x) / 2;
	ft_init_my_draw_pixel(search, para, pos, pars);
}
