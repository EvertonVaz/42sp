/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:04:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/29 14:53:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putnbr_base(long int n, t_details details, int time)
{
	size_t	size;

	size = 0;
	if (time == 1 && !details.minus)
		size += ft_putwidth(details.width - ft_hexlen(n, time, details));
	if (details.flag == ' ' && (details.type == 'd' || details.type == 'i')
		&& time == 1 && n >= 0)
		size += write(1, " ", 1);
	else if (details.flag == '+' && (details.type == 'd' || details.type == 'i')
		&& time == 1 && n >= 0)
		size += write(1, "+", 1);
	if (n < 0)
	{
		n = -n;
		size += ft_putchar('-', details, 0);
	}
	if (n >= 10)
		size += ft_putnbr_base(n / 10, details, 0);
	size += ft_putchar(DECIMAL[n % 10], details, 0);
	if (time == 1 && details.minus)
		size += ft_putwidth(details.width - ft_hexlen(n, time, details));
	return (size);
}

size_t	ft_putnbr_hex(unsigned long num, t_details details, int time)
{
	size_t	size;
	int		base_len;
	char	*base;

	size = 0;
	if (time == 1 && !details.minus)
		size += ft_putwidth(details.width - ft_hexlen(num, time, details));
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
	size += ft_putchar(base[num % 16], details, 0);
	if (time == 1 && details.minus)
		size += ft_putwidth(details.width - ft_hexlen(num, time, details));
	return (size);
}

size_t	ft_put_pointer(unsigned long num, t_details details, int time)
{
	char	*base;
	size_t	size;

	size = 0;
	base = HEXALOW;
	if (time == 1 && !details.minus)
		size += ft_putwidth(details.width - ft_hexlen(num, time, details));
	if (num == 0)
		return (ft_putstr("(nil)", details, 0));
	if (num >= 16)
		size += ft_put_pointer(num / 16, details, 0);
	else
		size += ft_putstr("0x", details, 0);
	size += ft_putchar(base[num % 16], details, 0);
	if (time == 1 && details.minus)
		size += ft_putwidth(details.width - ft_hexlen(num, time, details));
	return (size);
}

size_t	ft_putstr(char *s, t_details details, int time)
{
	size_t	size;

	size = 0;
	if (time == 1 && !details.minus)
		size += ft_putwidth(details.width - ft_strlen(s));
	if (s)
	{
		while (s[size])
			write(1, &s[size++], 1);
	}
	else
		size += ft_putstr("(null)", details, 0);
	if (time == 1 && size == ft_strlen(s) && details.minus)
		size += ft_putwidth(details.width - ft_strlen(s));
	return (size);
}

size_t	put_percent(char flag, t_details details)
{
	size_t	size;

	size = 0;
	if (flag == ' ')
		size += ft_putchar(' ', details, 0);
	size += ft_putchar('%', details, 0);
	return (size);
}
