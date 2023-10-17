/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:59:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/17 18:42:22 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot(double real, double imag, t_fractol *st)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	iter = -1;
	r = real;
	i = imag;
	st->distance = 1.015;
	while (iter++ < st->max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 6.0)
		{
			st->distance = 1.015 * sqrt(r2 + i2) * log(sqrt(r2 + i2));
			return (iter);
		}
		i = 2 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (st->max_iter);
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
	while (st->x < st->img->width)
	{
		st->y = 0;
		while (st->y < st->img->height)
		{
			real = st->xmin + st->x * (st->xmax - st->xmin) / width;
			imag = st->ymin + st->y * (st->ymax - st->ymin) / heigth;
			iter = mandelbrot(real, imag, st);
			mandelbrot_color(iter, st);
			st->y++;
		}
		st->x++;
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
