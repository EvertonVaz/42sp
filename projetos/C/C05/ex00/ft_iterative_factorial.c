/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:12:58 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/13 13:17:49 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	aux;

	aux = nb;
	i = 1;
	if (nb == 0)
		return (1);
	while (aux > i)
	{
		nb *= i++;
	}
	if (nb < 0)
		return (0);
	return (nb);
}
