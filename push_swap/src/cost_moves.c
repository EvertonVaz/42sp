/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:33:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/11 15:57:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_ra(t_stack **stack, int cost)
{
	if (cost < 0)
		rra(stack);
	if (cost > 0)
		ra(stack);
}

void	moves_rb(t_stack **stack, int cost)
{
	if (cost < 0)
		rrb(stack);
	if (cost > 0)
		rb(stack);
}

void	moves_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	cost;

	cost = total_cost(*stack_b);
	if (cost < 0)
		rrr(stack_a, stack_b);
	if (cost > 0)
		rr(stack_a, stack_b);
}
