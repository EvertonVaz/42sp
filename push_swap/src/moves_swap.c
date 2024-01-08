/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:16:22 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 11:23:19 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_stack **head)
{
	if (!head || !*head || stack_len(*head) < 2)
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

void	sa(t_stack **a, int checker)
{
	if (swap(a) && !checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int checker)
{
	if (swap(b) && !checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int checker)
{
	if (swap(b) && swap(a) && !checker)
		write(1, "sb\n", 3);
}
