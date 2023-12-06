/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:27:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/06 20:57:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *lst)
{
	t_stack	*current;
	int		count;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
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

void	find_current_pos(t_stack *stack)
{
	int		index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
}
