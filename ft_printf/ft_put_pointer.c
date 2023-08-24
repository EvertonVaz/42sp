/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:00:00 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/24 09:14:32 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_pointer(unsigned long num)
{
	char	*base;
	size_t	size;

	base = "0123456789abcdef";
	size = 0;
	if (num >= 16)
		size += ft_put_pointer(num / 16);
	else
	{
		write(1, "0x", 2);
		size += 2;
	}
	size += ft_putchar(base[num % 16]);
	return (size);
}
