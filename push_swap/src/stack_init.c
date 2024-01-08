/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:17:28 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/04 11:20:02 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_fill(t_stack *stack)
{
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->current_pos = 0;
	stack->target_pos = 0;
	stack->index = 0;
	stack->next = NULL;
	stack->prev = NULL;
}

void	append_node(t_stack **stack, int value, int current_pos)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	stack_fill(node);
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

int	free_list(t_stack *head)
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
	return (EXIT_SUCCESS);
}
