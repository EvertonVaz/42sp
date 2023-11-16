/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:53:54 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/08 16:54:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_bonus(char c, t_details details, int time)
{
	size_t	size;

	size = 0;
	if (details.type == 'c' && details.width && !details.minus && time == 1)
		size += ft_putwidth(details.width - 1, details);
	size += write(1, &c, 1);
	if (details.type == 'c' && details.width && details.minus && time == 1)
		size += ft_putwidth(details.width - 1, details);
	return (size);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	find_type(const char *str)
{
	int		i;
	char	type;

	i = 0;
	type = 0;
	while (str[i])
	{
		if (ft_strchr_bonus(FORMATS, str[i]))
		{
			type = ft_strchr_bonus(FORMATS, str[i])[0];
			return (type);
		}
		i++;
	}
	return (type);
}

char	get_flag(char flag)
{
	if (ft_strchr_bonus(FLAGS, flag))
		return (ft_strchr_bonus(FLAGS, flag)[0]);
	return (0);
}

size_t	is_negative(int n, t_details details, int intlen, size_t size)
{
	if (n < 0)
	{
		if (details.flag == '0' && !details.minus)
		{
			size += ft_putchar_bonus('-', details, 0);
			size += ft_putwidth(details.width - intlen, details);
		}
		else if (!details.minus)
		{
			size += ft_putwidth(details.width - intlen, details);
			size += ft_putchar_bonus('-', details, 0);
		}
		else
			size += ft_putchar_bonus('-', details, 0);
	}
	return (size);
}
