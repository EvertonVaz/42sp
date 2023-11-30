/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:28:01 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/30 13:13:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!stack || !*stack || stack_len(*stack) < 2)
		return (0);
	last_node = find_last_node(*stack);
	tmp = last_node;
	last_node = last_node->prev;
	last_node->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
	return (1);
}

void	rra(t_stack **stack_a)
{
	if(reverse_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	if(reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if(reverse_rotate(stack_b) && reverse_rotate(stack_a))
		write(1, "rrr\n", 4);
}
