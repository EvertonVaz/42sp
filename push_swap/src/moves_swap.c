/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:16:22 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/06 10:45:30 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **head)
{
	if (!head || !*head || stack_len(*head) == 1)
		return (0);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (swap(b) && swap(a))
		write(1, "sb\n", 3);
}
