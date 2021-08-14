/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memorise_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:29 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:58:29 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_init_mlx(t_parsage *pars)
{
	int	sizex;
	int	sizey;

	pars->mlx.mlx = mlx_init();
	mlx_get_screen_size(pars->mlx.mlx, &sizex, &sizey);
	if (sizex < pars->reso.x)
		pars->reso.x = sizex;
	if (sizey < pars->reso.y)
		pars->reso.y = sizey;
	pars->mlx.window = mlx_new_window(pars->mlx.mlx, pars->reso.x,
			pars->reso.y, "Cub3d");
	pars->mlx.img.struct_img = mlx_new_image(pars->mlx.mlx, pars->reso.x,
			pars->reso.y);
	pars->mlx.img.adr = mlx_get_data_addr(pars->mlx.img.struct_img,
			&(pars->mlx.img.bitp), &(pars->mlx.img.linelength),
			&(pars->mlx.img.endian));
	mlx_put_image_to_window(pars->mlx.mlx, pars->mlx.window,
		pars->mlx.img.struct_img, 0, 0);
}

int	ft_init_texture(char *line, t_parsage *pars, int index)
{
	while (*line != '.' && *(line + 1) != '/' && *line != '\0')
		line++;
	if (*line == '\0')
		return (-1);
	pars->lst_texture[index].img_ptr = mlx_xpm_file_to_image(pars->mlx.mlx,
			line, &(pars->lst_texture[index].taille_x),
			&(pars->lst_texture[index].taille_y));
	if (pars->lst_texture[index].img_ptr == 0)
		return (-1);
	pars->lst_texture[index].data
		= mlx_get_data_addr(pars->lst_texture[index].img_ptr,
			&(pars->lst_texture[index].bpp),
			&(pars->lst_texture[index].taille_line),
			&(pars->lst_texture[index].endian));
	return (1);
}

int	ft_choose_texture(t_parsage *pars, char *line)
{
	int	res;

	res = 0;
	if (line[0] == 'N' && line[1] == 'O')
		res = ft_init_texture(line, pars, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		res = ft_init_texture(line, pars, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		res = ft_init_texture(line, pars, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		res = ft_init_texture(line, pars, 4);
	else if (line[0] == 'S')
		res = ft_init_texture(line, pars, 0);
	if (res == -1)
		return (-1);
	return (1);
}

int	ft_memorise_texture(t_parsage *pars, char *lien)
{
	int		fd;
	char	*line;
	int		x;
	int		res;

	res = 4;
	line = NULL;
	fd = open(lien, O_RDONLY, S_IRUSR);
	ft_init_mlx(pars);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		while (line[x] == ' ')
			x++;
		if ((line[x] == 'N' && line[x + 1] == 'O' && line[x + 2] == ' ')
			|| (line[x] == 'S' && line[x + 1] == 'O' && line[x + 2] == ' ')
			|| (line[x] == 'E' && line[x + 1] == 'A' && line[x + 2] == ' ')
			|| (line[x] == 'W' && line[x + 1] == 'E' && line[x + 2] == ' ')
			|| (line[x] == 'S' && line[x + 1] == ' '))
			if (ft_choose_texture(pars, &(line[x])) < 0)
				res = -1;
		free(line);
	}
	return (ft_fonction_fermeture_free(fd, &line, res));
}
