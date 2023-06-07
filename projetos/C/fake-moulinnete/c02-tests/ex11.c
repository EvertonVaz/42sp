/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:44:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/06/06 20:36:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char str[] = {'0', '1', 2, 30, 16, '4', 'a', 19, 'C'};

	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	printf("-- Exercicio 11: Compare as strings\n");
	char strtest0[] = {'0', '1', 3, 26, '2', '3', 12, 'f', '\n', 'a', 'b', '\0'};
	char strtest1[] = {'0', 'C', 'b', 127, 2, 'a', -82, 'b', -1, '\0'};

	char strans0[] = "01\\03\\1a23\\0cf\\0aab";
	char strans1[] = "0Cb\\7f\\02a\\aeb\\ff";

	ft_putstr_non_printable(strtest0);
	printf("\t==\t%s\n", strans0);

	ft_putstr_non_printable(strtest1);
	printf("\t==\t%s\n", strans1);

	printf("\n");
	return (0);
}
