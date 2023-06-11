/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:12:58 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/11 18:50:47 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	aux;

	aux = nb;
	i = 1;
	while (aux > i)
	{
		nb *= i++;
	}
	if (nb < 0)
		return (0);
	return (nb);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int n;

// 	n = -2;
// 	while (n <= 12)
// 	{
// 		printf("fact(%d) = %d\n", n, ft_iterative_factorial(n));
// 		n++;
// 	}
// }