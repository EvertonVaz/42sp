/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:43 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/08 12:29:25 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	stack_init(&stack_a, argv + 1);
	if (is_sorted(stack_a))
		return (free_list(stack_a));
	if (stack_len(stack_a) == 2)
		sa(&stack_a, 0);
	else if (stack_len(stack_a) == 3)
		sort_3(&stack_a);
	else
		push_swap(&stack_a, &stack_b);
	if (stack_b)
		free_list(stack_b);
	return (free_list(stack_a));
}
