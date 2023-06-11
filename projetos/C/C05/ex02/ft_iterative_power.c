/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:43:12 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/11 18:51:00 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	while (power > 1)
	{
		i *= nb;
		power--;
	}
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int nb;
// 	int power;

// 	printf("Enter a number: ");
// 	scanf("%d", &nb);
// 	printf("Enter a power: ");
// 	scanf("%d", &power);
// 	printf("%d\n", ft_iterative_power(nb, power));
// 	return (0);
// }