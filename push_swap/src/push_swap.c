/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:43 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/28 17:27:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_program(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_args(int n_args, char *args[])
{
	int	i;
	int	j;

	i = 0;
	if (n_args < 2)
		exit(EXIT_FAILURE);
	while (++i < (n_args - 1))
	{
		if ((!ft_isnum(args[i])) || (ft_atol(args[i]) > INT_MAX)
			|| (ft_atol(args[i]) < INT_MIN))
			end_program();
		j = i + 1;
		while (j < (n_args))
		{
			if (*args[i] == *args[j++])
				end_program();
		}
	}
}

#include "stdio.h"
int	main(int argc, char *argv[])
{
	int *stack_a;
	int i;

	i = 0;
	stack_a = malloc((argc - 1) * sizeof(int));
	check_args(argc, argv);
	while (argv[++i])
	{
		if (ft_isnum(argv[i]))
			stack_a[i - 1] = ft_atol(argv[i]);
	}
	i = -1;
	while (i++ < argc - 2)
		printf("%d, ", stack_a[i]);
	printf("\nfuncionou");
}