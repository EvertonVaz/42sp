/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:04:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/08/24 10:15:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(long int num, char *base)
{
	int		base_len;
	size_t	size;

	base_len = ft_strlen(base);
	size = 0;
	if (num < 0)
	{
		num = -num;
		size += ft_putchar('-');
	}
	if (num >= base_len)
		size += ft_putnbr_base(num / base_len, base);
	size += ft_putchar(base[num % base_len]);
	return (size);
}
