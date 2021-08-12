/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:34 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/26 12:32:37 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_next_line_2(char **lines, char *buf, int end_buff)
{
	char			*line_tmp;

	if (end_buff <= 0)
		return (-1);
	buf[end_buff] = '\0';
	line_tmp = NULL;
	line_tmp = *lines;
	*lines = ft_strjoin_2(line_tmp, buf);
	free(line_tmp);
	return (1);
}

int	ft_lines(char **lines)
{
	if (*lines == NULL)
	{
		*lines = ft_alloc(0);
		if (*lines == NULL)
			return (-1);
	}
	return (1);
}
