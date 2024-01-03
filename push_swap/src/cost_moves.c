/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:33:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 13:05:08 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	moves_ra(t_stack **stack, int cost)
{
	if (cost < 0)
		rra(stack, 0);
	if (cost > 0)
		ra(stack, 0);
}

void	moves_rb(t_stack **stack, int cost)
{
	if (cost < 0)
		rrb(stack, 0);
	if (cost > 0)
		rb(stack, 0);
}

void	moves_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	cost;

	cost = total_cost(*stack_b);
	if (cost < 0)
		rrr(stack_a, stack_b, 0);
	if (cost > 0)
		rr(stack_a, stack_b, 0);
}
