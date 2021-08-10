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

int	ft_remplie_valeur(t_parsage *pars, t_tmp *test, int option, t_tmp2 *a)
{
	int	option2;

	option2 = 0;
	if (option == 2)
		option2 = 1;
	else if (option == -2)
		option2 = -1;
	if (option == 2 || option == -2)
		option = 0;
	if (pars->map[test->y + option2][test->x + option] == '2')
	{
		pars->map[test->y + option2][test->x + option] = 'x';
		if (ft_bloker(test->y + option2, test->x + option, pars) == 0)
			return (-1);
	}
	else
	{
		pars->map[test->y + option2][test->x + option] = 'X';
		if (ft_bloker(test->y + option2, test->x + option, pars) == 0)
			return (-1);
	}
	a->x = test->x + option;
	a->y = test->y + option2;
	return (0);
}

int	ft_choose_case(t_parsage *pars, t_tmp *test)
{
	test->a1.x = -1;
	test->a2.x = -1;
	test->a3.x = -1;
	test->a4.x = -1;
	if (pars->map[test->y][test->x + 1] == '0' || pars->map[test->y][test->x + 1] == '2')
		if (ft_remplie_valeur(pars, test, 1, &(test->a1)) == -1)
			return (-1);
	if (pars->map[test->y][test->x - 1] == '0' || pars->map[test->y][test->x - 1] == '2')
		if (ft_remplie_valeur(pars, test, -1, &(test->a2)) == -1)
			return (-1);
	if (pars->map[test->y + 1][test->x] == '0' || pars->map[test->y + 1][test->x] == '2')
		if (ft_remplie_valeur(pars, test, 2, &(test->a3)) == -1)
			return (-1);
	if (pars->map[test->y - 1][test->x] == '0' || pars->map[test->y - 1][test->x] == '2')
		if (ft_remplie_valeur(pars, test, -2, &(test->a4)) == -1)
			return (-1);
	return (1);
}

int	ft_test(t_parsage *pars, t_tmp test, int *res)
{
	t_tmp	test2;

	test2.a1.x = 0;
	test2.a2.x = 0;
	test2.a3.x = 0;
	test2.a4.x = 0;
	if (ft_choose_case(pars, &test) == -1)
		*res = -1;
	if (test.a1.x != -1)
		ft_rempli_case_centre(pars, test2, res, test.a1);
	if (test.a2.x != -1)
		ft_rempli_case_centre(pars, test2, res, test.a2);
	if (test.a3.x != -1)
		ft_rempli_case_centre(pars, test2, res, test.a3);
	if (test.a4.x != -1)
		ft_rempli_case_centre(pars, test2, res, test.a4);
	return (1);
}

int		ft_recupe_info_map(t_parsage *pars, t_verif **info_map)
{
	int nb;
	int x;

	nb = 0;
	while (pars->map[nb][0] != '\0')
		nb++;
	*info_map = (t_verif *)malloc((sizeof(t_verif)) * (nb + 1));
	if (!*info_map)
		return (-1);
	(*info_map)[nb].x = -1;
	nb = 0;
	while (pars->map[nb][0] != '\0')
	{
		x = 0;
		while (pars->map[nb][x] != '\0')
			x++;
		(*info_map)[nb].y = nb;
		(*info_map)[nb].x = x;
		nb++;
	}  
	return (1);
}


int	ft_init_test_map(t_parsage *pars)
{
	t_tmp	test;
	int		res;

	res = 1;
	if (ft_recupe_info_map(pars, &(pars->info_map)) == -1)
		return (-1);
	if (pars->map[1][0] == '\0' || pars->map[0][0] == '\0')
		return (-1);
	if (ft_recherche_perso(pars->map, &test, pars) == -1)
		return (-1);
	ft_test(pars, test, &res);
	if (res < 0)
		return (-1);
	ft_netoyage(pars->map);
	return (res);
}
