/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:25:21 by egeraldo          #+#    #+#             */
/*   Updated: 2023/06/05 21:01:46 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

// bubble sort
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	aux;

	aux = 0;
	while (aux < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i +1];
				tab[i + 1] = temp;
			}
			i++;
		}
		aux++;
	}
}
