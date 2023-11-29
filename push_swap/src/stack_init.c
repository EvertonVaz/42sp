/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:17:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/29 14:27:21 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = value;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_stack **stack_a, char **argv)
{
	long	value;

	while (*argv)
	{
		value = atol(*argv++);
		append_node(stack_a, value);
	}
}

void	free_list(t_stack *head)
{
	t_stack	*temp;

	temp = NULL;
	while (head->next)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	free(head);
}
