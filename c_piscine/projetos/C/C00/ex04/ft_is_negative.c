/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:06:55 by egeraldo          #+#    #+#             */
/*   Updated: 2023/05/30 10:56:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	if (n > 0 || n == '\0')
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
}
