/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:54:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/17 18:22:04 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_color(t_colors *colors)
{
	colors->col1 = 0x8B0000; // verm
	colors->col2 = 0xFF6F00; // laranja
	colors->col3 = 0xFFD700; // amarelo
	colors->col4 = 0x944728; // marrom
	colors->col5 = 0x000000; // preto
	/* colors->col1 = 0xFFFFFF; // Branco para as flores
	colors->col2 = 0xFFFF00; // Amarelo para as flores
	colors->col3 = 0xFFA500; // Laranja para os centros das flores
	colors->col4 = 0x0000FF; // Azul profundo para o fundo
	colors->col5 = 0x000000; // Preto */
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
	double		interpolate;
	t_colors	c;

	interpolate = (double)iter / (double)st->max_iter;
	c.smooth = pow(interpolate, 0.347);
	init_color(&c);
	if (interpolate < 0.2)
		color = interpolate_color(c.col1, c.col2, st, c);
	else if (interpolate < 0.4)
		color = interpolate_color(c.col2, c.col1, st, c);
	else if (interpolate < 0.6)
		color = interpolate_color(c.col2, c.col3, st, c);
	else if (interpolate < 0.8)
		color = interpolate_color(c.col3, c.col4, st, c);
	else
		color = interpolate_color(c.col2, c.col5, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}

void	julia_color(int iter, t_fractol *st)
{
	uint32_t	color;
	double		interpolate;
	t_colors	c;

	init_color(&c);
	interpolate = (double)iter / (double)st->max_iter;
	c.smooth = pow(interpolate, 0.347);
	if (interpolate < 0.125)
		color = interpolate_color(0xFFFFFF, c.col5, st, c);
	else if (interpolate < 0.25)
		color = interpolate_color(c.col5, c.col3, st, c);
	else if (interpolate < 0.375)
		color = interpolate_color(c.col3, c.col2, st, c);
	else if (interpolate < 0.5)
		color = interpolate_color(c.col1, c.col4, st, c);
	else if (interpolate < 0.625)
		color = interpolate_color(c.col3, c.col2, st, c);
	else if (interpolate < 0.750)
		color = interpolate_color(c.col1, c.col3, st, c);
	else if (interpolate < 0.875)
		color = interpolate_color(c.col4, 0xFFFFFF, st, c);
	else
		color = interpolate_color(c.col4, c.col1, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}
