/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:18:09 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/29 14:37:03 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

size_t	ft_putwidth(int width)
{
	size_t	size;

	size = 0;
	while (width > 0 && width--)
		size += write(1, " ", 1);
	return (size);
}

void	reset_details(t_details *details)
{
	details->flag = 0;
	details->minus = 0;
	details->type = 0;
	details->width = 0;
}

void	wirte_details(t_details *details, const char *str)
{
	details->type = find_type(str + 1);
	details->flag = get_flag(*(str + 1));
	details->width = ft_atoi(str);
	if (ft_strchr(str, '-'))
		details->minus = ft_strchr(str, '-')[0];
	else
		details->minus = 0;
}
