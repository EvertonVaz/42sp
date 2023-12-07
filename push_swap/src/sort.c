/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:50:18 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/07 15:59:10 by egeraldo         ###   ########.fr       */
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

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	float	len;
	float	mid_index;

	len = stack_len(*stack_a);
	mid_index = len / 2;
	while (len > 3)
	{
		if ((*stack_a)->index <= mid_index)
		{
			pb(stack_a, stack_b);
			len--;
		}
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		pa(stack_b, stack_a);
		if (*stack_a && (*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
}

/* void	moviment(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && stack_b && (*stack_b)->next)
	{
		if ((*stack_a)->value > (*stack_a)->next->value && (*stack_b)->value < (*stack_b)->next->value)
			ss(stack_a, stack_b);
		else if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		else if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
} */

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
void	test(t_stack *stack, char name)
{
	t_stack	*temp;
	printf("\nPILHA %c\n", name);
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
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	double	len;

	len = send_to_b(stack_a, stack_b, stack_len(*stack_a));
	while (len-- > 3)
		pb(stack_a, stack_b);
	sort_3(stack_a);

	find_target_pos(stack_a, stack_b);
	test(*stack_a, 'A');
	test(*stack_b, 'B');
}