/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:36:30 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 16:24:01 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	choice_print(va_list arg, char type, char flag)
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
		size += ft_putnbr_base(va_arg(arg, int), flag, type, 1);
	else if (type == 'u')
		size += ft_putnbr_base(va_arg(arg, unsigned int), flag, type, 1);
	else if (type == 'x')
		size += ft_putnbr_hex(va_arg(arg, unsigned int), type, flag, 1);
	else if (type == 'X')
		size += ft_putnbr_hex(va_arg(arg, unsigned int), type, flag, 1);
	else if (type == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	char	flag;

	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			if (ft_strchr(FLAGS, *(format + 1)))
				flag = ft_strchr(FLAGS, *(format + 1))[0];
			size += choice_print(args, find_type(format + 1), flag);
			format = ft_strchr(format, find_type(format + 1));
		}
		else
			size += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (size);
}
