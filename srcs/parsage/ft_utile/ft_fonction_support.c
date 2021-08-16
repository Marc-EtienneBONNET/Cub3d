/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonction_support.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_procedure_verif_para(int *conteur, char *line, char para)
{
	int	x;

	x = 0;
	while (line[x] == ' ')
		x++;
	if (line[x] == para)
		*conteur += 1;
}

int	ft_verif_enti_dossier(char *lien)
{
	char	*line;
	int		fd;

	fd = open(lien, O_RDONLY | __O_NOFOLLOW, S_IRUSR);
	line = NULL;
	if (get_next_line(fd, &line) == -1)
	{
		close(fd);
		free(line);
		return (-1);
	}
	free(line);
	close(fd);
	return (1);
}

int	ft_verif_nb_para(char *lien, char para)
{
	int		fd;
	char	*line;
	int		conteur;

	conteur = 0;
	if (ft_verif_enti_dossier(lien) == -1)
		return (-1);
	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	while (get_next_line(fd, &line) > 0)
	{
		ft_procedure_verif_para(&conteur, line, para);
		free(line);
	}
	ft_procedure_verif_para(&conteur, line, para);
	free(line);
	close(fd);
	if (conteur != 1)
		return (-1);
	return (1);
}

int	ft_fonction_fermeture_free(int fd, char *line, int retour)
{
	close(fd);
	free(line);
	return (retour);
}
