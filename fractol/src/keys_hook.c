/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:54:49 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/09 19:32:39 by egeraldo         ###   ########.fr       */
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
