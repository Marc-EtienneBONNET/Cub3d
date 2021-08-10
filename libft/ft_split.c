/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:44:45 by mbonnet           #+#    #+#             */
/*   Updated: 2021/05/04 17:22:01 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_word(char *s, char c)
{
	int	x;
	int	res;

	res = 0;
	x = 0;
	if (s[0] != c)
		res = 1;
	while (s[++x])
		if (s[x - 1] == c && (s[x] == '\0' || s[x] != c))
			res++;
	return (res);
}

int	ft_len_word(char *s, char c)
{
	int	x;

	x = -1;
	while (s[++x])
		if ((s[x + 1] == c || s[x + 1] == '\0') && s[x] != c)
			return (x + 1);
	return (0);
}

char	*ft_init_smol_word(char *s, char c, int len)
{
	char	*res;
	int		i;
	int		x;

	x = 0;
	i = -1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (++i < len)
	{
		while (s[i] == c)
			i++;
		res[x++] = s[i];
	}
	return (res);
}

void	ft_init_word(char *s, char **res, char c, int nb_words)
{
	int	x;
	int	len;

	x = -1;
	len = 0;
	while (++x < nb_words)
	{
		while (*s == c)
			s += 1;
		len = ft_len_word(s, c);
		res[x] = ft_init_smol_word(s, c, len);
		s += len;
		while (*s == c)
			s += 1;
	}
	res[x] = "\0";
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_words;

	if (!s || s[0] == '\0')
	{
		res = (char **)malloc(sizeof(char *) * 1);
		if (!(res))
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	nb_words = ft_nb_word((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!(res))
		return (NULL);
	ft_init_word((char *)s, res, c, nb_words);
	res[nb_words] = NULL;
	return (res);
}
