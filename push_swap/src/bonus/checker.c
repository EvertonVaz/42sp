/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:51:19 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/03 13:01:19 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	fill_function_list(t_actions **list, void *function, char *name)
{
	(*list)->name = name;
	(*list)->function = function;
	(*list)->next = NULL;
}

void	choice_function(char *function, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(function, "sa", ft_strlen(function)))
		return(sa(stack_a, 1));
	if (ft_strncmp(function, "sb", ft_strlen(function)))
		return(sb(stack_b, 1));
	if (ft_strncmp(function, "ss", ft_strlen(function)))
		return(ss(stack_a, stack_b, 1));
	if (ft_strncmp(function, "pa", ft_strlen(function)))
		return(pa(stack_b, stack_a, 1));
	if (ft_strncmp(function, "pb", ft_strlen(function)))
		return(pb(stack_a, stack_b, 1));
	if (ft_strncmp(function, "ra", ft_strlen(function)))
		return(ra(stack_a, 1));
	if (ft_strncmp(function, "rb", ft_strlen(function)))
		return(rb(stack_b, 1));
	if (ft_strncmp(function, "rr", ft_strlen(function)))
		return(rr(stack_a, stack_b, 1));
	if (ft_strncmp(function, "rra", ft_strlen(function)))
		return(rra(stack_a, 1));
	if (ft_strncmp(function, "rrb", ft_strlen(function)))
		return(rrb(stack_b, 1));
	if (ft_strncmp(function, "rrr", ft_strlen(function)))
		return(rrr(stack_a, stack_b, 1));
}

#include <stdio.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
	char *line;

	if(argv)
		;
	(void)argc;
	while(argc+3)
	{
		line = get_next_line(0);
		printf("checker, %s", line);
		free(line);
		argc--;
	}
	return (0);
}
