/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:43 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/29 14:30:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((!ft_isnum(args[i])) || (ft_atol(args[i]) > INT_MAX)
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

#include "stdio.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	check_args(argc, argv);
	stack_init(&stack_a, argv + 1);
	while (stack_a->next)
	{
		printf("%d, ", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
