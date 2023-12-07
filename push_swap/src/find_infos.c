/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:39 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/07 15:47:58 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(char **argv)
{
	int	i;
	int	j;
	char *temp;

	i = -1;
	while (argv[++i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) > ft_atol(argv[j]))
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
	}
}

void	find_index(t_stack **stack_a, char **argv)
{
	int		current_pos;
	t_stack	*temp;

	current_pos = 0;
	temp = *stack_a;
	bubble_sort(argv);
	while (argv[current_pos] && temp)
	{
		if (ft_atol(argv[current_pos]) == temp->value)
		{
			temp->index = current_pos + 1;
			temp = temp->next;
			current_pos = -1;
		}
		current_pos++;
	}
}

void	find_current_pos(t_stack *stack)
{
	int		current_pos;

	current_pos = 0;
	while (stack)
	{
		stack->current_pos = current_pos;
		stack = stack->next;
		current_pos++;
	}
}

void	find_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	find_current_pos(*stack_a);
	while (temp_a)
	{
		temp_b = *stack_b;
		while (temp_b)
		{
			if (temp_b->index +1 == temp_a->index || temp_b->index -1 == temp_a->index)
			{
				temp_b->target_pos = temp_a->current_pos;
				break;
			}
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
}

// void	find_cost(t_stack *stack);