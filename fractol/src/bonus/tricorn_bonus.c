/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:59:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/19 17:26:07 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

static int	tricorn(double real, double imag, t_fractol *st)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	iter = -1;
	r = real;
	i = imag;
	while (++iter < st->max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 6.0)
			return (iter);
		i = -2.0 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (st->max_iter);
}

static void	tricorn_color(int iter, t_fractol *st)
{
	uint32_t	color;
	double		interpolate;
	t_colors	c;

	init_color(&c);
	interpolate = (double)iter / (double)st->max_iter;
	c.smooth = pow(interpolate, 0.347);
	if (interpolate < 0.125)
		color = st->ccolor * interpolate_color(0xDDDDDD, c.col5, st, c);
	if (interpolate >= 0.125 && interpolate < 0.25)
		color = st->ccolor * interpolate_color(c.col5, c.col3, st, c);
	if (interpolate >= 0.25 && interpolate < 0.375)
		color = st->ccolor * interpolate_color(c.col3, c.col2, st, c);
	if (interpolate >= 0.375 && interpolate < 0.5)
		color = st->ccolor * interpolate_color(c.col1, c.col4, st, c);
	if (interpolate >= 0.5 && interpolate < 0.625)
		color = st->ccolor * interpolate_color(c.col3, c.col2, st, c);
	if (interpolate >= 0.625 && interpolate < 0.750)
		color = st->ccolor * interpolate_color(c.col1, c.col3, st, c);
	if (interpolate >= 0.750 && interpolate < 0.875)
		color = st->ccolor * interpolate_color(c.col4, 0xEEEEEE, st, c);
	if (interpolate >= 0.875)
		color = st->ccolor * interpolate_color(c.col4, c.col1, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}

void	display_tricorn(t_fractol *st)
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
			iter = tricorn(real, imag, st);
			tricorn_color(iter, st);
			st->y++;
		}
		st->x++;
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
