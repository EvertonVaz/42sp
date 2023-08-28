/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:00:00 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/28 14:32:33 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_put_pointer(unsigned long num)
{
	char	*base;
	size_t	size;

	base = "0123456789abcdef";
	size = 0;
	if (num == 0)
		return (ft_putstr("(nil)"));
	if (num >= 16)
		size += ft_put_pointer(num / 16);
	else
		size += ft_putstr("0x");
	size += ft_putchar(base[num % 16]);
	return (size);
}
