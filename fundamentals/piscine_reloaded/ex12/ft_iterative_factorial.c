/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:19:55 by egeraldo          #+#    #+#             */
/*   Updated: 2023/07/12 18:03:22 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	aux;

	result = 1;
	aux = nb;
	if (nb == 0)
		return (1);
	else if ((nb < 0) || (nb > 12))
		return (0);
	while (aux > result)
		nb *= result++;
	return (nb);
}
