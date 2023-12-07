/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:17:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/07 10:05:54 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack **stack, int value, int current_pos)
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
	node->current_pos = current_pos;
}

void	stack_init(t_stack **stack_a, char **argv)
{
	long	value;
	int		current_pos;

	current_pos = 0;
	while (argv[current_pos])
	{
		value = atol(argv[current_pos]);
		append_node(stack_a, value, current_pos++);
	}
	find_index(stack_a, argv);
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
