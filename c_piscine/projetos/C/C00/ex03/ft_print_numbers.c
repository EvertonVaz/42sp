/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:36:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/05/30 10:56:19 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	numbers;

	numbers = 0;
	while (numbers <= 9)
	{
		ft_putchar(numbers + '0');
		numbers++;
	}		
}
