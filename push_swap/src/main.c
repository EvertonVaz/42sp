/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:43 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/07 11:13:38 by egeraldo         ###   ########.fr       */
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
		stack_a = stack_a->next;
	}
	return (1);
}

#include <stdio.h>
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("index: %d | ", stack->index);
		printf("current pos %d | ", stack->current_pos);
		printf("taget pos %d | ", stack->target_pos);
		printf("value %d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	check_args(argc, argv);
	stack_init(&stack_a, argv + 1);
	if (is_sorted(stack_a))
		return (EXIT_SUCCESS);
	find_current_pos(stack_a);
	// print_stack(stack_a);
	if (stack_len(stack_a) == 2)
		sa(&stack_a);
	if (stack_len(stack_a) == 3)
		sort_3(&stack_a);
	else
		push_swap(&stack_a, &stack_b);
	find_current_pos(stack_a);
	// print_stack(stack_a);
	free_list(stack_a);
	return (EXIT_SUCCESS);
}
