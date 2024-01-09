/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:09:51 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 11:22:28 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_move(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	(*dest)->prev = NULL;
	return (1);
}

void	pa(t_stack **stack_b, t_stack **stack_a, int checker)
{
	if (push_move(stack_b, stack_a) && !checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int checker)
{
	if (push_move(stack_a, stack_b) && !checker)
		write(1, "pb\n", 3);
}
