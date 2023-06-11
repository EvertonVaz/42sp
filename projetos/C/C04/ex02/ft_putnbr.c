/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:41:01 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/08 17:44:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Escreva uma função que mostre um número passado como parâmetro. A função
// deverá ser capaz de mostrar a totalidade dos valores possíveis em uma
// variável de tipo int.

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (0);
		}
		else
		{
			ft_putchar('-');
			nb = -nb;
		}
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar('0' + nb % 10);
}
