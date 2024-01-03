/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:51:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/12/15 14:43:48 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	fill_function_list(t_actions **list, void *function, char *name)
{
	(*list)->name = name;
	(*list)->function = function;
	(*list)->next = NULL;
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
