/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:04:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 16:35:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putnbr_base(long int num, char flag, char type, int time)
{
	int		base_len;
	size_t	size;
	char	*base;

	base = DECIMAL;
	base_len = ft_strlen(base);
	size = 0;
	if (flag == ' ' && (type == 'd' || type == 'i') && time == 1)
		size += write(1, " ", 1);
	else if (flag == '+' && (type == 'd' || type == 'i') && time == 1)
		size += write(1, "+", 1);
	if (num < 0)
	{
		num = -num;
		size += ft_putchar('-');
	}
	if (num >= base_len)
		size += ft_putnbr_base(num / base_len, flag, type, 0);
	size += ft_putchar(base[num % base_len]);
	return (size);
}

size_t	ft_putnbr_hex(unsigned long num, char type, char flag, int time)
{
	size_t	size;
	int		base_len;
	char	*base;

	size = 0;
	if (type == 'X')
		base = HEXAUPP;
	else
		base = HEXALOW;
	base_len = ft_strlen(base);
	if (flag == '#' && type == 'X' && num > 0 && time == 1)
		size += write(1, "0X", 2);
	else if (flag == '#' && type == 'x' && num > 0 && time == 1)
		size += write(1, "0x", 2);
	if (num >= 16)
		size += ft_putnbr_hex(num / 16, type, flag, 0);
	size += ft_putchar(base[num % 16]);
	return (size);
}
