/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:59:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/10 12:33:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(double real, double imag, int max_iter)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	iter = -1;
	r = real;
	i = imag;
	while (iter++ < max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 20.0)
			return (iter);
		i = 2 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (max_iter);
}

void	display_mandelbrot(t_fractol *st)
{
	int		width;
	int		heigth;
	int		iter;
	double	real;
	double	imag;

	st->x = 0;
	width = (st->img->width - 1);
	heigth = (st->img->height - 1);
	while (st->x++ < (int)st->img->width)
	{
		st->y = -1;
		while (st->y++ < (int)st->img->height)
		{
			real = st->xmin + st->x * (st->xmax - st->xmin) / width;
			imag = st->ymin + st->y * (st->ymax - st->ymin) / heigth;
			iter = mandelbrot(real, imag, st->max_iter);
			calculate_color(iter, st);
		}
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
