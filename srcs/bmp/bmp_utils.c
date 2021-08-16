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

#include "cub3d.h"

int	bmp(t_parsage *pars, char *lien)
{
	int	x;

	x = 0;
	if (ft_lance_parsage(pars, lien) < 0)
		return (-1);
	ft_protocol_raycasting_bmp(pars);
	if (save_bmp(pars->reso, *pars))
		ft_putstr("file save.bmp created.\n");
	return (1);
}

int	get_correction_byte(int image_width)
{
	char	correction_byte[4];

	correction_byte[0] = 0;
	correction_byte[1] = 3;
	correction_byte[2] = 2;
	correction_byte[3] = 1;
	return (correction_byte[(int)(3 * image_width) % 4]);
}
