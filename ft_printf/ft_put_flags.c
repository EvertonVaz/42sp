/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:44:05 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/25 20:37:09 by egeraldo         ###   ########.fr       */
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
			return(ft_strchr(FORMATS, str[i])[0]);
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

int	invalid_flag(char flag, char after_flag, char type)
{
	if ((flag == '#' || flag == '+') && after_flag != type)
		return (1);
	return (0);
}