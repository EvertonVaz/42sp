/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:41:01 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/12 12:49:15 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Escreva uma função que mostre um número passado como parâmetro. A função
// deverá ser capaz de mostrar a totalidade dos valores possíveis em uma
// variável de tipo int.

void	ft_putnbr(int nb);

void	print_nbr(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2", 2);
			nb = 147483648;
		}
		else
		{
			print_nbr('-');
			nb = -nb;
		}
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	print_nbr('0' + nb % 10);
}
