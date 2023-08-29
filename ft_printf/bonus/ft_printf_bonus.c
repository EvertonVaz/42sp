/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:36:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/29 16:47:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	choice_print(va_list arg, t_details details)
{
	size_t	size;

	size = 0;
	if (details.type == 'c')
		size += ft_putchar_bonus(va_arg(arg, int), details, 1);
	else if (details.type == 's')
		size += ft_putstr_bonus(va_arg(arg, char *), details, 1);
	else if (details.type == 'p')
		size += ft_put_pointer(va_arg(arg, unsigned long), details, 1);
	else if (details.type == 'd' || details.type == 'i')
		size += ft_putnbr_base(va_arg(arg, int), details, 1);
	else if (details.type == 'u')
		size += ft_putnbr_base(va_arg(arg, unsigned int), details, 1);
	else if (details.type == 'x')
		size += ft_putnbr_hex(va_arg(arg, unsigned int), details, 1);
	else if (details.type == 'X')
		size += ft_putnbr_hex(va_arg(arg, unsigned int), details, 1);
	else if (details.type == '%')
		size += put_percent(details.flag, details);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			size;
	t_details	details;

	size = 0;
	va_start(args, format);
	reset_details(&details);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			wirte_details(&details, format);
			size += choice_print(args, details);
			if (details.type == '%')
				format++;
			else
				format = ft_strchr_bonus(format, details.type);
		}
		else
			size += ft_putchar_bonus(*format, details, 0);
		format++;
	}
	va_end(args);
	reset_details(&details);
	return (size);
}
