/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_programe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:00:55 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:14 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_close_vm(t_parsage *pars)
{
	if (pars->mlx.window != NULL && pars->mlx.mlx != NULL)
	{
		mlx_clear_window(pars->mlx.mlx, pars->mlx.window);
		mlx_destroy_image(pars->mlx.mlx, pars->mlx.img.struct_img);
		mlx_destroy_window(pars->mlx.mlx, pars->mlx.window);
	}
	if (pars->info_map != NULL)
		free(pars->info_map);
}

int	ft_close_programe(t_parsage *pars, int choose)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (pars->lien != NULL)
		free(pars->lien);
	if (pars->map != NULL)
	{
		while (pars->map[y][0] != '\0')
			free(pars->map[y++]);
		free(pars->map[y++]);
		free(pars->map);
	}
	if (choose == -2)
		free(pars->obj);
	while (pars->lst_texture[x].img_ptr != NULL)
		mlx_destroy_image(pars->mlx.mlx, pars->lst_texture[x++].img_ptr);
	ft_close_vm(pars);
	if (pars->mlx.mlx)
	{
		mlx_loop_end(pars->mlx.mlx);
		mlx_destroy_display(pars->mlx.mlx);
		free(pars->mlx.mlx);
	}
	exit (0);
	return (1);
}
