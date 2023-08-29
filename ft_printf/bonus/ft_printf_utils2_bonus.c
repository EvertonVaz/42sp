/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:27:53 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 21:06:33 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	get_flag(char flag)
{
	if (ft_strchr(FLAGS, flag))
		return (ft_strchr(FLAGS, flag)[0]);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= ' ' && str[i] <= '0'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	while(n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_putwidth(int width)
{
	size_t	size;

	size = 0;
	while(width--)
	{
		ft_putchar(' ');
		size++;
	}
	return (size);
}
