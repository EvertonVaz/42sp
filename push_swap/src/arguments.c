/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:07:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 14:08:15 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	end_program(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_args(int n_args, char *args[])
{
	int	i;
	int	j;

	i = 0;
	if (n_args < 2)
		exit(EXIT_FAILURE);
	while (++i < n_args)
	{
		if ((!args[i][0] || !ft_isnum(args[i])) || (ft_atol(args[i]) > INT_MAX)
			|| (ft_atol(args[i]) < INT_MIN))
			end_program();
		j = i + 1;
		while (j < (n_args))
		{
			if (ft_atol(args[i]) == ft_atol(args[j++]))
				end_program();
		}
	}
}
