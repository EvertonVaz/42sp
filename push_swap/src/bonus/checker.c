/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:51:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 18:05:47 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	choice_function(char *function, t_stack **stack_a, t_stack **stack_b)
{
	if (!function)
		return ;
	if (ft_strncmp(function, "sa\n", 3) == 0)
		sa(stack_a, 1);
	else if (ft_strncmp(function, "sb\n", 3) == 0)
		sb(stack_b, 1);
	else if (ft_strncmp(function, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strncmp(function, "pa\n", 3) == 0)
		pa(stack_b, stack_a, 1);
	else if (ft_strncmp(function, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 1);
	else if (ft_strncmp(function, "ra\n", 3) == 0)
		ra(stack_a, 1);
	else if (ft_strncmp(function, "rb\n", 3) == 0)
		rb(stack_b, 1);
	else if (ft_strncmp(function, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strncmp(function, "rra\n", 4) == 0)
		rra(stack_a, 1);
	else if (ft_strncmp(function, "rrb\n", 4) == 0)
		rrb(stack_b, 1);
	else if (ft_strncmp(function, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 1);
}

int main(int argc, char **argv)
{
	char	*function;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	stack_init(&stack_a, argv + 1);
	function = "";
	while(function)
	{
		function = get_next_line(0);
		choice_function(function, &stack_a, &stack_b);
		free(function);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	return (0);
}
