/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:40:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/15 12:10:01 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct s_actions
{
	char				*name;
	void				*function;
	struct s_actions	*next;
}						t_actions;

# include "push_swap.h"

#endif