/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:03:40 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/14 16:32:57 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}

/* int	main(void)
{
	int *range;
	int i = 0;
	int test = ft_ultimate_range(&range, 10, 5);
	int test2 = ft_ultimate_range(&range, 10, 50);
	while (range[i] != '\0')
		printf("%i, ", range[i++]);
	printf("\nretorno da função %i\n", test);
	printf("\nretorno da função %i\n", test2);
} */