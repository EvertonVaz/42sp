/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:53:54 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/29 12:20:03 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	put_porcent(char flag)
{
	size_t	size;

	size = 0;
	if (flag == ' ')
		size += ft_putchar(' ');
	size += ft_putchar('%');
	return (size);
}

char	*ft_strchr(const char *s, int c)
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
		if (ft_strchr(FORMATS, str[i]))
		{
			type = ft_strchr(FORMATS, str[i])[0];
			return (type);
		}
		i++;
	}
	return (type);
}

char	get_flag(char flag)
{
	if (ft_strchr(FLAGS, flag))
		return (ft_strchr(FLAGS, flag)[0]);
	return (0);
}
