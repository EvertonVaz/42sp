/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:36:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/26 02:59:07 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	choice_print(va_list arg, char type)
{
	size_t	size;

	size = 0;
	if (type == 'c')
		size += ft_putchar(va_arg(arg, int));
	else if (type == 's')
		size += ft_putstr(va_arg(arg, char *));
	else if (type == 'p')
		size += ft_put_pointer(va_arg(arg, unsigned long));
	else if (type == 'd' || type == 'i')
		size += ft_putnbr_base(va_arg(arg, int), DECIMAL);
	else if (type == 'u')
		size += ft_putnbr_base(va_arg(arg, unsigned int), DECIMAL);
	else if (type == 'x')
		size += ft_putnbr_base(va_arg(arg, unsigned int), HEXALOW);
	else if (type == 'X')
		size += ft_putnbr_base(va_arg(arg, unsigned int), HEXALOW);
	else if (type == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, format);
	if (invalid_flag(format))
		return (-1);
	while (*format)
	{
		if (*format == '%' && *format + 1 != 0)
		{
			if (ft_strchr(FLAGS, *(format + 1)), *(format + 1))
			{
				size += put_flag(*(format + 1), find_type(format + 1));
			}
			size += choice_print(args, find_type(format + 1));
			format = ft_strchr(format, find_type(format + 1));
		}
		else
			size += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (size);
}
