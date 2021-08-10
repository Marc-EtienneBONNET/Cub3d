/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <webbonnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:34 by mbonnet           #+#    #+#             */
/*   Updated: 2020/11/26 12:32:37 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_witespace(const char *str)
{
	int	x;

	x = 0;
	while ((str[x] == ' ' || str[x] == '\n'
			|| str[x] == '\t' || str[x] == '\v'
			|| str[x] == '\f' || str[x] == '\r')
		&& str[x])
		x++;
	return (x);
}

int	ft_atoi(const char *str)
{
	unsigned int	x;
	unsigned int	signe;
	unsigned int	res;

	res = 0;
	x = 0;
	signe = 1;
	x = ft_witespace(str);
	if (str[x] == '-')
	{
		x++;
		signe *= -1;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		res *= 10;
		res += str[x] - '0';
		x++;
	}
	res *= signe;
	return (res);
}
