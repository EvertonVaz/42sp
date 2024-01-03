/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:50:18 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 11:25:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack)
{
	int	max;

	max = get_max(*stack)->value;
	if ((*stack)->value == max)
		ra(stack, 0);
	else if ((*stack)->next->value == max)
		rra(stack, 0);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 0);
}

int	send_to_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	mid_index;

	mid_index = len / 2;
	while (len > 3 && len > mid_index + 1)
	{
		if ((*stack_a)->index <= mid_index)
		{
			pb(stack_a, stack_b, 0);
			len--;
		}
		else
			ra(stack_a, 0);
	}
	return (len);
}

void	send_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*index_move;

	while (*stack_b)
	{
		find_target_pos(stack_a, stack_b, get_max(*stack_a), get_min(*stack_a));
		index_move = get_min_cost(*stack_b);
		if (index_move->cost_a != index_move->cost_b)
		{
			moves_ra(stack_a, index_move->cost_a);
			moves_rb(stack_b, index_move->cost_b);
		}
		else
			moves_rrr(stack_a, stack_b);
		if ((*stack_b)->index == index_move->index && total_cost(*stack_b) == 0)
			pa(stack_b, stack_a, 0);
	}
	find_current_pos(*stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	t_stack	*temp;
	int		first_pos;

	len = send_to_b(stack_a, stack_b, stack_len(*stack_a));
	while (len-- > 3)
		pb(stack_a, stack_b, 0);
	sort_3(stack_a);
	send_to_a(stack_b, stack_a);
	len = stack_len(*stack_a) / 2;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index == 1)
			first_pos = temp->current_pos;
		temp = temp->next;
	}
	while ((*stack_a)->index != 1)
	{
		if (first_pos <= len)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}
