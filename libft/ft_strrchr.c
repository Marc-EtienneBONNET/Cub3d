/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:46:22 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/19 12:11:28 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;

	res = (0);
	while (*str)
	{
		if (*str == c)
			res = (char *)str;
		str++;
	}
	if (res)
		return (res);
	if (c == '\0')
		return ((char *)str);
	return (0);
}
