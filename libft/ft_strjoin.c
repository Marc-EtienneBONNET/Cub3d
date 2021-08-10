/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:45:20 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/20 16:37:32 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	len;
	unsigned int	x;
	unsigned int	i;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen1((char *)s1) + ft_strlen1((char *)s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (s1[x])
	{
		res[x] = s1[x];
		x++;
	}
	while (s2[i])
	{
		res[x + i] = s2[i];
		i++;
	}
	res[x + i] = '\0';
	return (res);
}
