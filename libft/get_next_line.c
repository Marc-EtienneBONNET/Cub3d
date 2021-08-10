/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:06:14 by macbook           #+#    #+#             */
/*   Updated: 2021/02/25 15:24:20 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_line2(char *save)
{
	int	len;

	len = 0;
	if (save == NULL)
		return (0);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	return (ft_strsub2(save, 0, len));
}

char	*memorise2(char *save, char **line)
{
	int		len;
	char	*dst;

	len = 0;
	line[0] = new_line2(save);
	if (!save)
		return (0);
	while (save[len] != '\n' && save[len] != '\0')
		len++;
	if (!save[len])
	{
		free(save);
		return (0);
	}
	dst = ft_strsub2(save, len + 1, ft_strlen2(save));
	dst[ft_strlen2(save)] = '\0';
	free(save);
	return (dst);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buf[BUFFER_SIZE + 1];
	int			descriptor;

	descriptor = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (save == NULL)
		save = ft_strnew2(1);
	while (!ft_strchr2(save, '\n') && descriptor != 0)
	{
		descriptor = read(fd, buf, BUFFER_SIZE);
		if (descriptor == -1)
			return (-1);
		else if (descriptor == 0)
			break ;
		buf[descriptor] = '\0';
		save = ft_strjoin2(save, buf, descriptor);
	}
	save = memorise2(save, line);
	if (descriptor <= 0)
		return (0);
	return (1);
}
