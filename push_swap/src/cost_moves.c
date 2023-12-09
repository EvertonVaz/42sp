/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:33:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/09 14:52:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
