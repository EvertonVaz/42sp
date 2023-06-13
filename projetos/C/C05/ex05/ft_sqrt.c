/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:06:21 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/12 15:50:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb && nb <= 2147395600)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	for(int i = 1; i <= 50; i++)
// 	{
// 		if (ft_sqrt(i) != 0)
// 			printf("raiz de %i - %i\n", i, ft_sqrt(i));
// 	}
// 	printf("raiz de %i - %i\n", 2147395600, ft_sqrt(2147395600));
// }