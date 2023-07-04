/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:18:31 by etovaz            #+#    #+#             */
/*   Updated: 2023/07/04 10:15:28 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

void	fill_corners(int x, int y, int lin)
{
	int	col;

	col = 1;
	while (col != x + 1)
	{
		if (lin == 1 || lin == y)
		{
			if (col == 1)
				ft_putchar('A');
			else if (col == x)
				ft_putchar('C');
			else
				ft_putchar('B');
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
				ft_putchar('B');
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
