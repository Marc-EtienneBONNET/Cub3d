/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3d.h"

int	ft_bloker(int y, int x, t_parsage *pars)
{
	if (y == 0 || x == 0)
		return (0);
	if (pars->info_map[y + 1].x <= x || pars->info_map[y - 1].x <= x)
		return (0);
	if (ft_verif_cara("102NSEWXx", pars->map[y][x - 1]) == -1
	|| ft_verif_cara("102NSEWXx", pars->map[y][x + 1]) == -1
	|| ft_verif_cara("102NSEWXx", pars->map[y - 1][x]) == -1
	|| ft_verif_cara("102NSEWXx", pars->map[y + 1][x]) == -1)
		return (0);
	return (1);
}
