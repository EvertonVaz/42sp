/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lens_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:27:53 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/29 13:44:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_intlen(int n, t_details details)
{
	size_t	size;

	size = 0;
	if (details.flag == ' ')
		size++;
	else if (details.flag == '+')
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

size_t	ft_hexlen(unsigned long n, int time, t_details details)
{
	size_t	size;

	size = 0;
	if ((details.flag == '#' || details.type == 'p') && n > 0 && time == 1)
		size += 2;
	if (n >= 16)
		size += ft_hexlen(n / 16, 0, details);
	size++;
	return (size);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}
