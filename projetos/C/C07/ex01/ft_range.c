/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:44:15 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/13 16:10:30 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • Escreva uma função ft_range que retorne uma matriz de int. 
// Essa matriz de int deverá conter todos os valores entre min e max.
// • Min incluído - max excluído.
// • Se o valor min for superior ou igual ao valor max, 
// um ponteiro nulo será retornado.

#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc((max - min) * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		arr[i++] = min++;
	return (arr);
}

#include <stdio.h>

int main()
{
	int *arr = ft_range(1, 5);
	while (*arr)
	{
		printf("%i, ", *arr++);
	}
}