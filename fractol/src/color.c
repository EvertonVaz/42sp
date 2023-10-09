/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:54:28 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/09 19:35:42 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_color(mlx_image_t *img, int iter, t_fractol *st)
{
	double	interpolation_factor;
	double	smoothed_factor;
	int		color;

	interpolation_factor = (double)iter / (double)st->max_iter;
	smoothed_factor = pow(interpolation_factor, 0.85);
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
	mlx_put_pixel(img, st->x, st->y, color);
}
