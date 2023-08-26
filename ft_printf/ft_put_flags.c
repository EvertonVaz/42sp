/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:05 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/26 03:50:09 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// strchr(str, '%')[strchr(str, FORMATS)] = '\0'

#include "ft_printf.h"
char	find_type(const char *str)
{
	int		i;
	char	type;

	i = 0;
	type = 0;
	while(str[i])
	{
		if (ft_strchr(FORMATS, str[i]))
		{
			type = ft_strchr(FORMATS, str[i])[0];
			return(type);
		}
		i++;
	}
	return (type);
}

int	put_flag(char flag, char type)
{
	int size;

	size = 0;
	if (flag == ' ' && (type == 'd' || type == 'i'))
		size += write(1, " ", 1);
	else if (flag == '+' && (type == 'd' || type == 'i'))
		size += write(1, "+", 1);
	else if (flag == '#')
	{
		if (type == 'X')
			size += write(1, "0X", 2);
		else
			size += write(1, "0x", 2);
	}
	return (size);
}

int	invalid_flag(const char *format)
{
	char *flag;
	char type;
	
	while (*format)
	{
		flag = ft_strchr(FLAGS, *format);
		type = find_type(format);
		if (type == '%')
			type = 0;
		if (flag != NULL && (*flag == '#' || *flag == '+') && *(format + 1) != type)
			return (1);	
		format++;
	}

	return (0);
}