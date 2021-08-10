/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:06:42 by macbook           #+#    #+#             */
/*   Updated: 2021/02/25 15:24:27 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strsub2(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		s2[i] = s[start++];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin2(char *s1, char *s2, int descriptor)
{
	char			*res;
	unsigned int	x;
	unsigned int	i;

	i = -1;
	x = -1;
	s2[descriptor] = '\0';
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(char) * ((ft_strlen2((char *)s1)
					+ ft_strlen2((char *)s2) + 1)));
	if (!(res))
		return (NULL);
	while (s1[++x])
		res[x] = s1[x];
	while (s2[++i])
		res[x + i] = s2[i];
	res[x + i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr2(const char *str, int c)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == c)
			return ((char *)str + x);
		x++;
	}
	if (str[x] == c)
		return ((char *)str + x);
	return (NULL);
}

char	*ft_strnew2(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}
