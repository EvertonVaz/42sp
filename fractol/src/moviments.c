/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:54:49 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/06 20:27:01 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

double	calculate_pan_factor(t_fractol *fractol)
{
	double	mov;

	mov = (0.2 / (1.0 / (fractol->xmax - fractol->xmin)));
	printf("pan factor %.10f\n", mov);
	if (mov > 0.5)
		return (0.5);
	return (mov);
}

void	up_down(t_fractol *fractol)
{
	double	pan_factor;

	pan_factor = 0;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->ymin -= pan_factor;
		fractol->ymax -= pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->ymin += pan_factor;
		fractol->ymax += pan_factor;
	}
}

void	rigth_left(t_fractol *fractol)
{
	double	pan_factor;

	pan_factor = 0;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->xmin -= pan_factor;
		fractol->xmax -= pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->xmax += pan_factor;
		fractol->xmin += pan_factor;
	}
}

void zoom_scroll(double xdelta, double ydelta, void* param)
{
	t_fractol *st = param;
	double	zoom_factor;

	zoom_factor = 0.08;
	if ((int)xdelta == 1 || (int)ydelta == 1)
	{
		st->xmin = st->xmin + zoom_factor * (st->xmax - st->xmin);
		st->xmax = st->xmax - zoom_factor * (st->xmax - st->xmin);
		st->ymin = st->ymin + zoom_factor * (st->ymax - st->ymin);
		st->ymax = st->ymax - zoom_factor * (st->ymax - st->ymin);
		printf("ydelta %f, xdelta %f\n", xdelta, ydelta);
	}
	if ((int)xdelta == -1 || (int)ydelta == -1)
	{
		st->xmin = st->xmin - zoom_factor * (st->xmax - st->xmin);
		st->xmax = st->xmax + zoom_factor * (st->xmax - st->xmin);
		st->ymin = st->ymin - zoom_factor * (st->ymax - st->ymin);
		st->ymax = st->ymax + zoom_factor * (st->ymax - st->ymin);
		printf("ydelta %f, xdelta %f\n", xdelta, ydelta);
	}
}

void	mouse_click_move(t_fractol *fractol)
{
	int	xpos;
	int	ypos;

	if (mlx_is_mouse_down(fractol->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		mlx_get_mouse_pos(fractol->mlx, &xpos, &ypos);
		fractol->img->instances[0].x = xpos;
		fractol->img->instances[0].y = ypos;
		printf("xpos %d, ypos %d\n", xpos, ypos);
		printf("xpos img %f, ypos img %f\n", fractol->xmax, fractol->ymax);
	}
}