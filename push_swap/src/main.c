/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:43 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/06 22:44:52 by codespace        ###   ########.fr       */
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

void	print_elements(t_stack *stack, char title)
{
	printf("                        STACK %c                       \n", title);
	printf("|-----------------|-----------------|-----------------|\n");
	printf("| %-15s | %-15s | %-15s |\n", "prev->value", "value",
		"next->value");
	printf("|-----------------|-----------------|-----------------|\n");
	while (stack)
	{
		printf("| %-15d | %-15d | %-15d |\n",
			(stack->prev != NULL) ? stack->prev->value : 0x0, stack->value,
			(stack->next != NULL) ? stack->next->value : 0x0);
		stack = stack->next;
		if (stack != NULL)
			printf("|-----------------|-----------------|-----------------|\n");
	}
	printf("|-----------------|-----------------|-----------------|\n");
	printf("\n");
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("index: %d - %d\n", stack->index, stack->value);
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
	print_stack(stack_a);
	if (stack_len(stack_a) == 2)
		sa(&stack_a);
	if (stack_len(stack_a) == 3)
		sort_3(&stack_a);
	free_list(stack_a);
	return (EXIT_SUCCESS);
}
