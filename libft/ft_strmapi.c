/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:45:57 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/20 16:43:20 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		x;
	int		len;
	char	*res;

	x = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s && f) || !(res))
		return (NULL);
	while (s[x])
	{
		res[x] = (*f)(x, s[x]);
		x++;
	}
	res[x] = '\0';
	return (res);
}
