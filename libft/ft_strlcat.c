/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:45:29 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/19 14:57:06 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	i;
	unsigned int	z;

	i = 0;
	x = 0;
	z = 0;
	while (dst[x])
		x++;
	while (src[z])
		z++;
	if (size <= x)
		return (size + z);
	while (x + i < size - 1 && src[i])
	{
		dst[x + i] = src[i];
		i++;
	}
	dst[x + i] = '\0';
	return (z + x);
}
