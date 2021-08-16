/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lancemeny_parsage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verif_lien_info_cub(char *lien, t_parsage *pars)
{
	int	x;
	int	fd;

	x = 0;
	while (lien[x] != '\0')
		x++;
	x--;
	while (lien[x] == ' ')
		x--;
	if (lien[x] == 'b' && lien[x - 1] == 'u' && lien[x - 2] == 'c'
		&& lien[x - 3] == '.')
	{
		fd = open(lien, O_RDONLY, S_IRUSR);
		if (fd <= 0)
		{
			close(fd);
			return (-1);
		}
		close(fd);
		pars->lien = ft_strdup(lien);
		return (1);
	}
	else
		return (-1);
}

int	ft_erreur(char *erreur, int x)
{
	ft_putstr("\nErreur d'init du doc info\n");
	ft_putstr(erreur);
	return (x);
}

int	ft_lance_parsage(t_parsage *pars, char *lien)
{
	if (ft_init_recup_reso(pars, lien) < 0)
		return (ft_erreur("procédure ft_init_recup_reso)\n\n", -1));
	if (ft_init_recup_ciel_terre(pars, lien) < 0)
		return (ft_erreur(": (procédure ft_init_recup_ciel_terre)\n\n", -1));
	if (ft_init_verif_texture(lien) < 0)
		return (ft_erreur("(procédure ft_init_verif_texture)\n\n", -1));
	if (ft_memorise_texture(pars, lien) < 0)
		return (ft_erreur("(procédure ft_memorise_texture)\n\n", -1));
	if (ft_verif_dernier_line_info_cub(lien) < 0)
		return (ft_erreur("(procédure ft_verif_dernier_line_info_cub)\n\n", -1));
	if (ft_recup_map(pars) < 0)
		return (ft_erreur("(procédure ft_recup_map)\n\n", -1));
	if (ft_init_test_map(pars) < 0)
		return (ft_erreur("procédure ft_init_test_map)\n\n", -1));
	ft_init_ray(pars);
	if (ft_init_obj(pars) < 0)
		return (ft_erreur("(procédure ft_init_obj)\n\n", -2));
	return (1);
}
