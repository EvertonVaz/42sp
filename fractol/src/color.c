/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:54:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/10 12:37:31 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#include <math.h>

/* void calculate_color(mlx_image_t *img, int iter, t_fractol *fractol)
{
    double mu = iter + 1 - (log(log(iter)) / log(2.0));
    double mu_normalized = mu / fractol->max_iter;  // Normaliza mu

    // Use funções trigonométricas para criar variações nas cores
    fractol->r = (uint8_t)(127 * sin(2.0 * M_PI * mu_normalized));
    fractol->g = (uint8_t)(127 * sin(2.0 * M_PI * mu_normalized + 2.0));
    fractol->b = (uint8_t)(127 * sin(2.0 * M_PI * mu_normalized + 4.0));

    int color = (fractol->r << 24) | (fractol->g << 16) | (fractol->b << 8) | 255;
    mlx_put_pixel(img, fractol->x, fractol->y, color);
} */


void	calculate_color(int iter, t_fractol *st)
{
	double	interpolation_factor;
	double	smoothed_factor;
	int		color;

	interpolation_factor = (double)iter / (double)st->max_iter;
	smoothed_factor = pow(interpolation_factor, 0.6);
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
