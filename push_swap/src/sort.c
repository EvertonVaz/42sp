/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:50:18 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/11 17:24:39 by egeraldo         ###   ########.fr       */
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

#include <stdio.h>
/* static void	test(t_stack *stack, char name)
{
	printf("\nPILHA %c\n", name);
	if (!stack)
		return ;
	t_stack	*temp;
	temp = stack;
	printf("valores:\t");
	while (temp)
	{
		printf("|%4d| ", temp->value);
		temp = temp->next;
	}
	temp = stack;
	printf("\nindices:\t");
	while (temp)
	{
		printf("[%4d] ", temp->index);
		temp = temp->next;
	}
	temp = stack;
	printf("\nposicoes:\t");
	while (temp)
	{
		printf("<%4d> ", temp->current_pos);
		temp = temp->next;
	}
	temp = stack;
	printf("\ntaget pos:\t");
	while (temp)
	{
		printf("(%4d) ", temp->target_pos);
		temp = temp->next;
	}
	temp = stack;
	printf("\nCOST   A:\t");
	while (temp)
	{
		printf("|%4d| ", temp->cost_a);
		temp = temp->next;
	}
	temp = stack;
	printf("\nCOST   b:\t");
	while (temp)
	{
		printf("|%4d| ", temp->cost_b);
		temp = temp->next;
	}
} */

void	send_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*index_move;

	while (*stack_b)
	{
		find_target_pos(stack_a, stack_b);
		index_move = get_min_cost(*stack_b);
		if ((*stack_b)->cost_a != (*stack_b)->cost_b)
		{
			moves_ra(stack_a, index_move->cost_a);
			moves_rb(stack_b, index_move->cost_b);
		}
		else if (total_cost(*stack_b) > 0)
			moves_rrr(stack_a, stack_b);
		if ((*stack_b)->index == index_move->index && total_cost(*stack_b) == 0)
			pa(stack_b, stack_a);
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	double	len;

	len = send_to_b(stack_a, stack_b, stack_len(*stack_a));
	while (len-- > 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);
	send_to_a(stack_b, stack_a);
	find_current_pos(*stack_a);
	while((*stack_a)->index != 1)
	{
		if ((*stack_a)->current_pos <= (stack_len(*stack_a) / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	if ((*stack_a)->index != 1)
		rra(stack_a);
}
