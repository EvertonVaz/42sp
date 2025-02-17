/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:27:53 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/08 16:53:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(long long int n, t_details details)
{
	size_t	size;

	size = 0;
	if (details.flag == ' ')
		size++;
	else if (details.flag == '+')
		size++;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

size_t	ft_hexlen(unsigned long long n, int time, t_details details)
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

size_t	ft_strlen_bonus(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}
