/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:03 by egeraldo          #+#    #+#             */
/*   Updated: 2023/11/28 17:17:24 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

# include "../libs/libft/libft.h"
# include "unistd.h"
# include "stdlib.h"

void	check_args(int n_args, char *args[]);

#endif