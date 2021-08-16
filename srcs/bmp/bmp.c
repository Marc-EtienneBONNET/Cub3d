/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:52:05 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 15:54:25 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_header	fill_bmp_header(t_reso img_res)
{
	t_header		frame_head;
	int				img_size;

	img_size = (3 * img_res.y * img_res.x)
		+ img_res.y * get_correction_byte(img_res.x);
	ft_bzero(&frame_head, sizeof(t_header));
	frame_head.signature[0] = 'B';
	frame_head.signature[1] = 'M';
	frame_head.size = sizeof(t_header) - 2 + img_size;
	frame_head.offset_img = sizeof(t_header) - 2;
	frame_head.reserved = 0;
	frame_head.img_header.size_img_header = sizeof(t_img_header);
	frame_head.img_header.width = img_res.x;
	frame_head.img_header.height = img_res.y;
	frame_head.img_header.nb_planes = 1;
	frame_head.img_header.bpp = BYTES_FORMAT;
	frame_head.img_header.size_img = img_size;
	return (frame_head);
}

t_bmp	ft_mlx_pixel_get_3(t_img texture, int x, int y, t_parsage pars)
{
	int		color;
	int		*data_int;
	t_bmp	color_fin;

	data_int = (int *)texture.adr;
	color = data_int[y * pars.reso.x + (int)(x)];
	color_fin.r = (color & 0xFFFF00) >> 16;
	color_fin.g = (color & 0xFF00) >> 8;
	color_fin.b = (color & 0xFF);
	return (color_fin);
}

void	fill_bmp(t_header header, int fd, t_parsage pars)
{
	t_bmp			color;
	unsigned char	pixel_color[3];
	t_reso			coord;
	int				offset_byte;

	coord.y = -1;
	offset_byte = get_correction_byte(header.img_header.width);
	write(fd, &header, 2);
	write(fd, (char *)(&header) + 4, sizeof(t_header) - 4);
	coord.y = header.img_header.height;
	while (coord.y-- > 0)
	{
		coord.x = -1;
		while (++coord.x < header.img_header.width)
		{
			color = ft_mlx_pixel_get_3(pars.mlx.img, coord.x, coord.y, pars);
			pixel_color[0] = color.b;
			pixel_color[1] = color.g;
			pixel_color[2] = color.r;
			write(fd, pixel_color, 3);
		}
		ft_bzero(pixel_color, 3);
		write(fd, pixel_color, offset_byte);
	}
}

int	save_bmp(t_reso img_res, t_parsage pars)
{
	int				fd;
	t_header		header;

	fd = open(BMP_FILE_NAME, O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
		return (0);
	header = fill_bmp_header(img_res);
	fill_bmp(header, fd, pars);
	if (close(fd) == -1)
		return (0);
	return (1);
}
