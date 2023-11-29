/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:43 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/29 19:45:34 by egeraldo         ###   ########.fr       */
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

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
	}
	return (1);
}

#include "stdio.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	stack_init(&stack_a, argv + 1);
	// swap(&stack_a);
	rotate(&stack_a, &stack_b);
	printf("\nstack A\n");
	while (stack_a)
	{
		printf("%d, ", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("\nstack B\n");
	while (stack_b)
	{
		printf("%d, ", stack_b->value);
		stack_b = stack_b->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
