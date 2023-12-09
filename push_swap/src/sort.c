/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:50:18 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/09 14:52:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	send_to_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	mid_index;

	mid_index = len / 2;
	while (len > 3 && len > mid_index + 1)
	{
		if ((*stack_a)->index <= mid_index)
		{
			pb(stack_a, stack_b);
			len--;
		}
		else
			ra(stack_a);
	}
	return (len);
}

void	push_to_a(t_stack **stack_b, t_stack **stack_a)
{
	int	index_move;
	t_stack *temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		find_target_pos(stack_a, stack_b);
		index_move = get_min_cost(temp_b);
		if (temp_b->index == index_move)
		{
			if ((*stack_b)->cost_a != (*stack_b)->cost_b)
			{
				moves_ra(stack_a, (*stack_b)->cost_a);
				moves_rb(stack_b, (*stack_b)->cost_b);
			}
			else
				moves_rrr(stack_a, stack_b);
			pa(stack_b, stack_a);
			temp_b = *stack_b;
		}
		else
			temp_b = temp_b->next;
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	double	len;

	len = send_to_b(stack_a, stack_b, stack_len(*stack_a));
	while (len-- > 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	find_target_pos(stack_a, stack_b);
	push_to_a(stack_b, stack_a);
	if ((*stack_a)->index != 1)
		rra(stack_a);
}
