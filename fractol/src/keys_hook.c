/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:54:49 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/23 17:29:41 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	calculate_pan_factor(t_fractol *fractol)
{
	double	mov;

	mov = (0.2 / (1.0 / (fractol->xmax - fractol->xmin)));
	if (mov > 0.5)
		return (0.5);
	return (mov);
}

void	up_down(t_fractol *fractol)
{
	double	pan_factor;

	pan_factor = 0;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_W))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->ymin -= pan_factor;
		fractol->ymax -= pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_S))
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
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_A))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->xmin -= pan_factor;
		fractol->xmax -= pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_D))
	{
		pan_factor = calculate_pan_factor(fractol);
		fractol->xmax += pan_factor;
		fractol->xmin += pan_factor;
	}
}

void	zoom_keys(void *param)
{
	t_fractol	*st;
	double		zoom_factor;
	double		xrange;
	double		yrange;

	st = param;
	zoom_factor = 0.08;
	xrange = st->xmax - st->xmin;
	yrange = st->ymax - st->ymin;
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_ADD) || mlx_is_key_down(st->mlx,
			MLX_KEY_EQUAL))
	{
		st->xmin = st->xmin + zoom_factor * xrange;
		st->xmax = st->xmax - zoom_factor * xrange;
		st->ymin = st->ymin + zoom_factor * yrange;
		st->ymax = st->ymax - zoom_factor * yrange;
	}
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_SUBTRACT)
		|| mlx_is_key_down(st->mlx, MLX_KEY_MINUS))
	{
		st->xmin = st->xmin - zoom_factor * xrange;
		st->xmax = st->xmax + zoom_factor * xrange;
		st->ymin = st->ymin - zoom_factor * yrange;
		st->ymax = st->ymax + zoom_factor * yrange;
	}
}
