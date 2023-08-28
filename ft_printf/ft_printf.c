/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:36:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 14:49:08 by egeraldo         ###   ########.fr       */
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
		size += ft_putnbr_base(va_arg(arg, unsigned int), HEXAUPP);
	else if (type == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			size += choice_print(args, format[i + 1]);
			i++;
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}
