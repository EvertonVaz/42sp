/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:49:17 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/12 18:06:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int nb);
int ft_is_prime(int nb);
int ft_find_next_prime(int nb);

void fibonacci_test(int index)
{
	int queue[index+1];
	int i = 0;

	while (i < index)
	{
		if (i == 0)
			queue[i] = 0;
		else if (i == 1)
			queue[i] = 1;
		else
			queue[i] = (queue[i - 1]) + (queue[i - 2]);
		i++;
	}
	i = 0;
	while (i < index)
	{
		printf("%i, ", queue[i]);
		i++;
	}
}

int	main(void)
{
	printf("EXERCICIO 00\n");
	int n;
	int i = 0;
	
	n = -2;
	while (n <= 12)
	{
		printf("fact(%d) = %d\n", n, ft_iterative_factorial(n));
		n++;
	}
	
	printf("\nEXERCICIO 01\n");
	n = -2;
	while (n <= 12)
	{
		printf("fact(%d) = %d\n", n, ft_recursive_factorial(n));
		n++;
	}
	
	printf("\nEXERCICIO 02\n");
	int nb;
	int power;

	printf("Enter a number: ");
	scanf("%d", &nb);
	printf("Enter a power: ");
	scanf("%d", &power);
	printf("%d\n", ft_iterative_power(nb, power));

	printf("\nEXERCICIO 03\n");
	
	printf("Enter a number: ");
	scanf("%d", &nb);
	printf("Enter a power: ");
	scanf("%d", &power);
	printf("%d\n", ft_recursive_power(nb, power));

	printf("\nEXERCICIO 04\n");

	fibonacci_test(10);
	printf("\n");
	i = 0;
	while (i < 10)
	{
		printf("%d\n", ft_fibonacci(i));
		i++;
	}
	
	printf("\nEXERCICIO 05\n");
	for(int i = 1; i <= 50; i++)
	{
		if (ft_sqrt(i) != 0)
			printf("raiz de %i é %i\n", i, ft_sqrt(i));
	}
	printf("raiz de %i - %i\n", 2147395600, ft_sqrt(2147395600));
	
	printf("\nEXERCICIO 06\n");

	for(int i = 1; i <= 50; i++)
	{
		if (ft_is_prime(i) != 0)
			printf("n primo %i - yes? %i\n", i, ft_is_prime(i));
	}
	
	printf("\nEXERCICIO 07\n");
	
	printf("raiz de - %i\n", ft_find_next_prime(42));
}