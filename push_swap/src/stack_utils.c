/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:27:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/04 19:02:04 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *lst)
{
	t_stack	*current;
	int		count;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack	*get_max(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	temp = stack;
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->value == max)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_stack	*get_min(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	temp = stack;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->value == min)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
