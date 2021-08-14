/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:00:55 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:14 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_suite(t_parsage *pars, char **av)
{
	int	x;

	x = ft_lance_parsage(pars, av[1]);
	if (x < 0)
	{
		ft_putstr("Parametre fichier .cub non valide\n");
		ft_close_programe(pars);
		return (-1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_parsage	pars;

	ft_bzero(&pars, sizeof(t_parsage));
	if (ac != 2)
	{
		ft_putstr("Nombre de parametre non valide\n");
		return (-1);
	}
	if (ft_verif_lien_info_cub(av[1], &pars) < 0)
	{
		ft_putstr("Lien fichier .cub non valable\n");
		ft_close_programe(&pars);
		return (-1);
	}
	if (ft_suite(&pars, av) == -1)
		return (-1);
	protocole_draw(&pars);
	ft_close_programe(&pars);
	return (1);
}
