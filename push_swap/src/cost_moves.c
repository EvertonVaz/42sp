/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:36:44 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/08 20:22:55 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(int len, t_stack *stack, char cost_name, int current_pos)
{
	if (cost_name == 'a')
	{
		if (current_pos <= (len / 2))
			stack->cost_a = current_pos;
		else
			stack->cost_a = current_pos - len;
	}
	else
	{
		if (current_pos <= (len / 2))
			stack->cost_b = current_pos;
		else
			stack->cost_b = current_pos - len;
	}
}

int	total_cost(t_stack *stack)
{
	int	cost;

	cost = 0;
	if (stack->cost_a < 0)
		cost += stack->cost_a * -1;
	else
	 	cost += stack->cost_a;
	if (stack->cost_b < 0)
		cost += stack->cost_b * -1;
	else
		cost += stack->cost_b;
	return (cost);
}

int	get_min_cost(t_stack *stack)
{
	int min_cost;
	t_stack *temp;

	min_cost = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (total_cost(temp) < min_cost)
			min_cost = total_cost(temp);
		temp = temp->next;
	}
	while (stack)
	{
		if (total_cost(stack) == min_cost)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	moves_ra(t_stack **stack, int cost)
{
	int	aux;

	if (cost < 0)
		aux = cost * -1;
	else
	 	aux = cost;
	while (*stack && aux != 0)
	{
		if (cost < 0)
			rra(stack);
		else
			ra(stack);
		aux--;
	}
}
void	moves_rb(t_stack **stack, int cost)
{
	int	aux;

	if (cost < 0)
		aux = cost * -1;
	else
	 	aux = cost;
	{
		while (*stack && aux != 0)
		{
			if (cost < 0)
				rrb(stack);
			else
				rb(stack);
			aux--;
		}
	}
}

void	moves_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	cost;
	int	aux;

	cost = total_cost(*stack_b);
	if (cost < 0)
		aux = cost * -1;
	else
	 	aux = cost;
	while (*stack_a && *stack_b &&  aux != 0)
	{
		if (cost < 0)
			rrr(stack_a, stack_b);
		else
			rr(stack_a, stack_b);
		aux--;
	}
}
