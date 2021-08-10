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

int	ft_suite(t_parsage *pars, int ac, char **av)
{
	int x;

	if (ac == 2)
		x = ft_lance_parsage(pars, av[1]);
	else if (ac == 3 && ft_strncmp(av[2], "--save", 20) == 0)
	{
		if (bmp(pars, av[1]) < 0)
		{
			ft_close_programe(pars, -2);
			return (-1);
		}
		ft_close_programe(pars, -2);
		return (1);
	}
	if (ac == 2 && x < 0)
	{
		ft_putstr("Parametre fichier .cub non valide\n");
		ft_close_programe(pars, x);
		return (-1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_parsage	pars;

	ft_bzero(&pars, sizeof(t_parsage));
	if (ac < 2 || ac > 3)
	{
		ft_putstr("Nombre de parametre non valide\n");
		return (-1);
	}
	if (ft_verif_lien_info_cub(av[1], &pars) < 0)
	{
		ft_putstr("Lien fichier .cub non valable\n");
		ft_close_programe(&pars, 0);
		return (-1);
	}
	if (ft_suite(&pars, ac, av) == -1)
		return (-1);
	protocole_draw(&pars);
	ft_close_programe(&pars, -2);
	return (1);
}
