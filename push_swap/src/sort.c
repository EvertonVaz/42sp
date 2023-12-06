/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:50:18 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/06 20:13:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	sort_3(t_stack **stack)
{
	int	max;

	max = get_max(*stack);
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	while ((*stack_a)->value != min && (*stack_a)->value != max)
		ra(stack_a);
	if ((*stack_a)->value == min)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->value == min)
		ra(stack_a);
	else
	{
		ra(stack_a);
		ra(stack_a);
	}
}
