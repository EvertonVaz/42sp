/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:53:54 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 16:25:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			write(1, &s[i++], 1);
	}
	else
		i += ft_putstr("(null)");
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
