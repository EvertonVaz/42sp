/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:59:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/04 20:12:11 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"


int	mandelbrot(double real, double imag, int max_iter)
{
	int	iter;
	double r;
	double i;
	double r2;
	double i2;


	iter = -1;
	r = real;
	i = imag;
	while (iter++ < max_iter)
	{
		r2 = r * r;
		i2 = i * i;
		if ((r2 + i2) > 4.0)
			return (iter);
		i = 2 * r * i + imag;
		r = r2 - i2 + real;
	}
	return (max_iter);
}


void calculate_color(mlx_image_t *image, int x, int y, int iter, t_fractol *fractol)
{
    double interpolation_factor = (double)iter / (double)fractol->max_iter;

    if (interpolation_factor < 0.5) {
        interpolation_factor *= 2;
        fractol->r = (unsigned char)(150);
        fractol->g = (unsigned char)(interpolation_factor * 255);
        fractol->b = 10;
    }
    else
	{
        interpolation_factor = (interpolation_factor - 0.5) * 2;
        fractol->r = (unsigned char)((1 - interpolation_factor) * 255);
        fractol->g = (unsigned char)((1 - interpolation_factor) * 255);
        fractol->b = (unsigned char)((1 - interpolation_factor) * 255);
    }

    int color = (fractol->r << 24) | (fractol->g << 16) | (fractol->b << 8) | 255;
    mlx_put_pixel(image, x, y, color);
}

void display_mandelbrot(t_fractol *fractol)
{
    int	x;
	int	y;
	int	iter;

	x = 0;
	while(x++ < (int)fractol->img->width)
	{
		y = -1;
		while(y++ < (int)fractol->img->height)
		{
			iter = mandelbrot(
				fractol->xmin + x * (fractol->xmax - fractol->xmin) / (fractol->img->width - 1),
				fractol->ymin + y * (fractol->ymax - fractol->ymin) / (fractol->img->height - 1),
				fractol->max_iter);
			calculate_color(fractol->img, x, y, iter, fractol);
		}
	}

    // Exibir a imagem na janela
    mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}
