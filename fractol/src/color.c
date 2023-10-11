/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:54:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/11 15:48:37 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_color(t_colors *colors)
{
	colors->col1 = 0x8B0000;
	colors->col2 = 0xFFA500;
	colors->col3 = 0xFFD700;
	colors->col4 = 0xFFFF00;
	colors->col5 = 0x000000;
}

int	interpolate_color(int col1, int col2, t_fractol *st, t_colors c)
{
	c.r1 = (col1 >> 16) & 0xFF;
	c.g1 = (col1 >> 8) & 0xFF;
	c.b1 = col1 & 0xFF;
	c.r2 = (col2 >> 16) & 0xFF;
	c.g2 = (col2 >> 8) & 0xFF;
	c.b2 = col2 & 0xFF;
	st->r = (int)(c.r1 + c.smooth * (c.r2 - c.r1));
	st->g = (int)(c.g1 + c.smooth * (c.g2 - c.g1));
	st->b = (int)(c.b1 + c.smooth * (c.b2 - c.b1));
	return ((st->r << 24) | (st->g << 16) | (st->b << 8) | 255);
}

void	mandelbrot_color(int iter, t_fractol *st)
{
	int			color;
	int			interval;
	t_colors	c;

	c.smooth = pow(((double)iter / (double)st->max_iter) / st->distance, 0.65);
	init_color(&c);
	interval = st->max_iter / 6;
	if (iter < interval)
		color = interpolate_color(c.col1, c.col2, st, c);
	else if (iter < interval * 1.5)
		color = interpolate_color(c.col2, c.col1, st, c);
	else if (iter < interval * 3)
		color = interpolate_color(c.col2, c.col3, st, c);
	else if (iter < interval * 4.5)
		color = interpolate_color(c.col4, c.col1, st, c);
	else
		color = interpolate_color(c.col3, c.col5, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}

void	julia_color(int iter, t_fractol *st)
{
	double	interpolation_factor;
	double	smoothed_factor;
	int		color;

	interpolation_factor = (double)iter / (double)st->max_iter * st->distance;
	smoothed_factor = pow(interpolation_factor, 0.9);
	if (interpolation_factor < 0.6)
	{
		st->r = 150;
		st->g = smoothed_factor * 255;
		st->b = 10;
	}
	else
	{
		st->r = ((1 - smoothed_factor) * 200);
		st->g = ((1 - smoothed_factor) * 255);
		st->b = ((1 - smoothed_factor) * 200);
	}
	color = (st->r << 24) | (st->g << 16) | (st->b << 8) | 255;
	mlx_put_pixel(st->img, st->x, st->y, color);
}