/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:54:49 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/05 11:43:28 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

double	calculate_pan_factor(t_fractol *fractol)
{
	double	mov;

	mov = (0.2 / (1.0 / (fractol->xmax - fractol->xmin)));
	printf("pan factor %f\n", mov);
	if (mov > 0.5)
		return (0.5);
	return (mov);
}

void	moviment_keys(t_fractol *fractol)
{
	double pan_factor = calculate_pan_factor(fractol);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		fractol->ymin -= pan_factor;
		fractol->ymax -= pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		fractol->ymin += pan_factor;
		fractol->ymax += pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		fractol->xmin -= pan_factor;
		fractol->xmax -= pan_factor;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		fractol->xmax += pan_factor;
		fractol->xmin += pan_factor;
	}
}

void	zoom_wheel(t_fractol *fractol)
{
	// Exemplo para zoom in
	double zoom_factor = 0.08;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_PAGE_DOWN))
	{
		fractol->xmin = fractol->xmin + zoom_factor * (fractol->xmax - fractol->xmin);
		fractol->xmax = fractol->xmax - zoom_factor * (fractol->xmax - fractol->xmin);
		fractol->ymin = fractol->ymin + zoom_factor * (fractol->ymax - fractol->ymin);
		fractol->ymax = fractol->ymax - zoom_factor * (fractol->ymax - fractol->ymin);
	}
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_PAGE_UP))
	{
		fractol->xmin = fractol->xmin - zoom_factor * (fractol->xmax - fractol->xmin);
		fractol->xmax = fractol->xmax + zoom_factor * (fractol->xmax - fractol->xmin);
		fractol->ymin = fractol->ymin - zoom_factor * (fractol->ymax - fractol->ymin);
		fractol->ymax = fractol->ymax + zoom_factor * (fractol->ymax - fractol->ymin);
	}
}