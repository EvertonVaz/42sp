/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:45:42 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/23 17:29:41 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mouse_click_move(t_fractol *st)
{
	double	x_half;
	double	y_half;

	x_half = ((st->xmax - st->xmin) / 2.0);
	y_half = ((st->ymax - st->ymin) / 2.0);
	if (mlx_is_mouse_down(st->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(st->mlx, &st->xpos, &st->ypos);
		st->xzoom = st->xmin + st->xpos * ((st->xmax - st->xmin) / st->width);
		st->yzoom = st->ymin + st->ypos * ((st->ymax - st->ymin) / st->height);
		st->xmin = st->xzoom - x_half;
		st->xmax = st->xzoom + x_half;
		st->ymin = st->yzoom - y_half;
		st->ymax = st->yzoom + y_half;
	}
}

void	zoom_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*st;
	double		zoom_factor;

	st = param;
	(void)xdelta;
	zoom_factor = 1.1;
	mlx_get_mouse_pos(st->mlx, &st->xpos, &st->ypos);
	st->xzoom = st->xmin + st->xpos * ((st->xmax - st->xmin) / st->width);
	st->yzoom = st->ymin + st->ypos * ((st->ymax - st->ymin) / st->height);
	if (ydelta > 0)
	{
		st->xmin = st->xzoom - (1.0 / zoom_factor) * (st->xzoom - st->xmin);
		st->xmax = st->xzoom + (1.0 / zoom_factor) * (st->xmax - st->xzoom);
		st->ymin = st->yzoom - (1.0 / zoom_factor) * (st->yzoom - st->ymin);
		st->ymax = st->yzoom + (1.0 / zoom_factor) * (st->ymax - st->yzoom);
	}
	if (ydelta < 0)
	{
		st->xmin = st->xzoom - zoom_factor * (st->xzoom - st->xmin);
		st->xmax = st->xzoom + zoom_factor * (st->xmax - st->xzoom);
		st->ymin = st->yzoom - zoom_factor * (st->yzoom - st->ymin);
		st->ymax = st->yzoom + zoom_factor * (st->ymax - st->yzoom);
	}
}

void	mouse_moviment(t_fractol *st)
{
	double	x_range;
	double	y_range;
	double	normalized_x;
	double	normalized_y;

	if (mlx_is_key_down(st->mlx, MLX_KEY_LEFT_SHIFT))
	{
		mlx_get_mouse_pos(st->mlx, &st->xpos, &st->ypos);
		x_range = st->xmax - st->xmin;
		y_range = st->ymax - st->ymin;
		normalized_x = (double)st->xpos / (double)st->width;
		normalized_y = (double)st->ypos / (double)st->height;
		st->creal = st->xmin + (normalized_x * 0.85) * x_range;
		st->cimag = st->ymin + (normalized_y * 0.85) * y_range;
	}
}
