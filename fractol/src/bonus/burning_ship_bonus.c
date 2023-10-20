/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:23:19 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/20 16:31:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

int	burning_ship(double real, double imag, t_fractol *st)
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
		r = fabs(r);
		i = fabs(i);
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 6.0)
			return (iter);
		i = 2 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (st->max_iter);
}

void	burning_ship_color(int iter, t_fractol *st)
{
	uint32_t	color;
	double		interpolate;
	t_colors	c;

	init_color(&c);
	interpolate = (double)iter / (double)st->max_iter;
	c.smooth = pow(interpolate, 0.347);
	if (interpolate < 0.2)
		color = st->ccolor * interpolate_color(c.col1, c.col2, st, c);
	if (interpolate >= 0.2 && interpolate < 0.4)
		color = st->ccolor * interpolate_color(c.col2, c.col1, st, c);
	if (interpolate >= 0.4 && interpolate < 0.6)
		color = st->ccolor * interpolate_color(c.col2, c.col3, st, c);
	if (interpolate >= 0.6 && interpolate < 0.8)
		color = st->ccolor * interpolate_color(c.col3, 0xffa94e, st, c);
	if (interpolate >= 0.8)
		color = st->ccolor * interpolate_color(c.col4, c.col5, st, c);
	mlx_put_pixel(st->img, st->x, st->y, color);
}

void	display_burning_ship(t_fractol *st)
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
			iter = burning_ship(real, imag, st);
			burning_ship_color(iter, st);
			st->y++;
		}
		st->x++;
	}
	mlx_image_to_window(st->mlx, st->img, 0, 0);
}
