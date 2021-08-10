/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:45:37 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/20 16:35:58 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	len;

	len = 0;
	x = 0;
	if (src == NULL)
		return (0);
	while (src[len])
		len++;
	if (size > 0)
	{
		while (x < size - 1 && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (len);
}
