/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:04:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/30 10:25:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putnbr_base(long long int n, t_details details, int time)
{
	size_t	size;
	size_t	intlen;

	size = 0;
	intlen = ft_intlen(n, details);
	if (time == 1 && !details.minus && n >= 0)
		size += ft_putwidth(details.width - ft_intlen(n, details), details);
	if (details.flag == ' ' && time == 1 && n >= 0)
		size += write(1, " ", 1);
	else if (details.flag == '+' && time == 1 && n >= 0)
		size += write(1, "+", 1);
	if (n < 0)
	{
		n = -n;
		size += ft_putchar_bonus('-', details, 0);
		if (details.zero && !details.minus)
			size += ft_putwidth(details.width - intlen, details);
	}
	if (n >= 10)
		size += ft_putnbr_base(n / 10, details, 0);
	size += ft_putchar_bonus(DECIMAL[n % 10], details, 0);
	if (time == 1 && details.minus && !details.zero)
		size += ft_putwidth(details.width - intlen, details);
	return (size);
}

size_t	ft_putnbr_hex(unsigned long long int num, t_details details, int time)
{
	size_t	size;
	char	*base;
	size_t	hexlen;

	hexlen = ft_hexlen(num, time, details);
	size = 0;
	if (time == 1 && !details.minus)
		size += ft_putwidth(details.width - hexlen, details);
	if (details.type == 'X')
		base = HEXAUPP;
	else
		base = HEXALOW;
	if (details.flag == '#' && details.type == 'X' && num > 0 && time == 1)
		size += write(1, "0X", 2);
	else if (details.flag == '#' && details.type == 'x' && num > 0 && time == 1)
		size += write(1, "0x", 2);
	if (num >= 16)
		size += ft_putnbr_hex(num / 16, details, 0);
	size += ft_putchar_bonus(base[num % 16], details, 0);
	if (time == 1 && details.minus)
		size += ft_putwidth(details.width - hexlen, details);
	return (size);
}

size_t	ft_put_pointer(unsigned long long num, t_details details, int time)
{
	char	*base;
	size_t	size;
	size_t	hexlen;

	hexlen = ft_hexlen(num, time, details);
	size = 0;
	base = HEXALOW;
	if (time == 1 && !details.minus)
		size += ft_putwidth(details.width - hexlen, details);
	if (num == 0)
		return (ft_putstr_bonus("(nil)", details, 0));
	if (num >= 16)
		size += ft_put_pointer(num / 16, details, 0);
	else
		size += ft_putstr_bonus("0x", details, 0);
	size += ft_putchar_bonus(base[num % 16], details, 0);
	if (time == 1 && details.minus)
		size += ft_putwidth(details.width - hexlen, details);
	return (size);
}

size_t	ft_putstr_bonus(char *s, t_details details, int time)
{
	size_t	size;
	size_t	i;
	size_t	strlen;
	size_t	width;

	strlen = ft_strlen_bonus(s);
	size = 0;
	if (!s)
		width = details.width - 6;
	else
		width = details.width - strlen;
	if (time == 1 && !details.minus)
		size += ft_putwidth(width, details);
	if (s)
	{
		i = 0;
		while (*s && s[i])
			size += write(1, &s[i++], 1);
	}
	else
		size += ft_putstr_bonus("(null)", details, 0);
	if (time == 1 && size == strlen && details.minus)
		size += ft_putwidth(width, details);
	return (size);
}

size_t	put_percent(char flag, t_details details)
{
	size_t	size;

	size = 0;
	if (flag == ' ')
		size += ft_putchar_bonus(' ', details, 0);
	size += ft_putchar_bonus('%', details, 0);
	return (size);
}
