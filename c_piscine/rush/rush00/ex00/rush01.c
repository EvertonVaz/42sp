/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:18:31 by etovaz            #+#    #+#             */
/*   Updated: 2023/07/04 10:26:14 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fill_corners(int x, int y, int lin)
{
	int	col;

	col = 1;
	while (col != x + 1)
	{
		if (lin == 1)
		{
			if (col == 1)
				ft_putchar('/');
			else if (col == x)
				ft_putchar('\\');
			else
				ft_putchar('*');
		}
		else if (lin == y)
		{
			if (col == 1)
				ft_putchar('\\');
			else if (col == x)
				ft_putchar('/');
			else
				ft_putchar('*');
		}
		col++;
	}
}

void	fill_middle(int x, int y, int lin)
{
	int	col;

	col = 1;
	while (col != x + 1)
	{
		if (lin != 1 && lin != y)
		{
			if ((col == 1 || col == x))
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		col++;
	}
}

void	rush(int x, int y)
{
	int	lin;

	lin = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (lin != y + 1)
	{
		fill_corners(x, y, lin);
		fill_middle(x, y, lin);
		lin++;
		ft_putchar('\n');
	}
}

int	main(void)
{
	rush(4, 4);
	rush(1, 1);
	rush(0, 4);
	rush(-4, 4);
	rush(4, -4);
	rush(5, 3);
	rush(1, 5);
	rush(5, 1);
	return (0);
}