/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_click.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_clik(int key, t_parsage *pars)
{
	if (key == 65363)
		pars->mouv.cam_droite = 124;
	if (key == 65361)
		pars->mouv.cam_gauche = 123;
	if (key == 119)
		pars->mouv.avant = 12;
	if (key == 115)
		pars->mouv.arriere = 6;
	if (key == 100)
		pars->mouv.gauche = 2;
	if (key == 97)
		pars->mouv.droite = 1;
	if (key == 65307)
		ft_close_programe(pars, -2);
	return (1);
}

int	ft_de_clik(int key, t_parsage *pars)
{
	if (key == 65363)
		pars->mouv.cam_droite = 0;
	if (key == 65361)
		pars->mouv.cam_gauche = 0;
	if (key == 119)
		pars->mouv.avant = 0;
	if (key == 115)
		pars->mouv.arriere = 0;
	if (key == 100)
		pars->mouv.gauche = 0;
	if (key == 97)
		pars->mouv.droite = 0;
	if (key == 65307)
		pars->mouv.sup = 0;
	if (key == 2021)
	{
		pars->mouv.cam_droite = 0;
		pars->mouv.cam_gauche = 0;
		pars->mouv.droite = 0;
		pars->mouv.gauche = 0;
		pars->mouv.avant = 0;
		pars->mouv.arriere = 0;
		pars->mouv.sup = 0;
	}
	return (1);
}
