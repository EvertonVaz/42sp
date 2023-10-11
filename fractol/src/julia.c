/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:44:21 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/11 15:41:20 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia(double real, double imag, t_fractol *st)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	iter = -1;
	r = real;
	i = imag;
	st->distance = 2.0;
	while (iter++ < st->max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 6.0)
		{
			st->distance = 2.0 * sqrt(r2 + i2) * log(sqrt(r2 + i2));
			return (iter);
		}
		i = 2 * r * i + st->cimag;
		r = r2 - i2 + st->creal;
	}
	return (st->max_iter);
}

void	display_julia(t_fractol *st)
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
			iter = julia(real, imag, st);
			julia_color(iter, st);
		}
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
