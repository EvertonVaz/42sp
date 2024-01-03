/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:39:55 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 11:23:43 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!stack || !*stack || stack_len(*stack) < 2)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	last_node = find_last_node(*stack);
	last_node->next = tmp;
	last_node->next->prev = last_node;
	return (1);
}

void	ra(t_stack **stack_a, int checker)
{
	if (rotate(stack_a) && !checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int checker)
{
	if (rotate(stack_b) && !checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int checker)
{
	if (rotate(stack_b) && rotate(stack_a) && !checker)
		write(1, "rr\n", 3);
}
