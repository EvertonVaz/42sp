/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:04:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/29 12:22:28 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putnbr_base(long int n, t_details details, int time)
{
	size_t	size;
	size_t	width;

	width = details.width - ft_intlen(n, details);
	if (time == 1)
		ft_putwidth(width);
	size = 0;
	if (details.flag == ' ' && (details.type == 'd' || details.type == 'i')
		&& time == 1 && n >= 0)
		size += write(1, " ", 1);
	else if (details.flag == '+' && (details.type == 'd' || details.type == 'i')
		&& time == 1 && n >= 0)
		size += write(1, "+", 1);
	if (n < 0)
	{
		n = -n;
		size += ft_putchar('-');
	}
	if (n >= 10)
		size += ft_putnbr_base(n / 10, details, 0);
	size += ft_putchar(DECIMAL[n % 10]);
	return (size);
}

size_t	ft_putnbr_hex(unsigned long num, t_details details, int time)
{
	size_t	size;
	int		base_len;
	char	*base;
	size_t	width;

	width = details.width - ft_hexlen(num, time, details);
	if (time == 1)
		ft_putwidth(width);
	size = 0;
	if (details.type == 'X')
		base = HEXAUPP;
	else
		base = HEXALOW;
	base_len = ft_strlen(base);
	if (details.flag == '#' && details.type == 'X' && num > 0 && time == 1)
		size += write(1, "0X", 2);
	else if (details.flag == '#' && details.type == 'x' && num > 0 && time == 1)
		size += write(1, "0x", 2);
	if (num >= 16)
		size += ft_putnbr_hex(num / 16, details, 0);
	size += ft_putchar(base[num % 16]);
	return (size);
}

size_t	ft_put_pointer(unsigned long num, t_details details, int time)
{
	char	*base;
	size_t	size;
	size_t	width;

	width = details.width - ft_hexlen(num, time, details);
	if (time == 1)
		ft_putwidth(width);
	base = HEXALOW;
	size = 0;
	if (num == 0)
		return (ft_putstr("(nil)", details, 0));
	if (num >= 16)
		size += ft_put_pointer(num / 16, details, 0);
	else
		size += ft_putstr("0x", details, 0);
	size += ft_putchar(base[num % 16]);
	return (size);
}

size_t	ft_putstr(char *s, t_details details, int time)
{
	int		i;
	size_t	width;

	if (time == 1)
	{
		width = details.width - ft_strlen(s);
		ft_putwidth(width);
	}
	i = 0;
	if (s)
	{
		while (s[i])
			write(1, &s[i++], 1);
	}
	else
		i += ft_putstr("(null)", details, 0);
	return (i);
}
