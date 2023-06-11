/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:52:13 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/11 19:12:06 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, --power));
}

// #include <stdio.h>

// int	main()
// {
// 	int nb;
// 	int power;

// 	printf("Enter a number: ");
// 	scanf("%d", &nb);
// 	printf("Enter a power: ");
// 	scanf("%d", &power);
// 	printf("%d\n", ft_recursive_power(nb, power));
// 	return (0);
// }