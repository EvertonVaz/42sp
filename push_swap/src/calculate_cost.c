/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:36:44 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/11 16:57:21 by egeraldo         ###   ########.fr       */
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

t_stack	*get_min_cost(t_stack *stack)
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
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
