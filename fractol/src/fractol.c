/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:59:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/04 11:07:45 by egeraldo         ###   ########.fr       */
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

void	calculate_color(mlx_image_t *image, int x, int y, int iter, t_fractol fractol)
{
	double mu;
	int color;

	mu = iter + 1 - (log(log(iter)) / log(2.0));
	fractol.r = 0x90;
	fractol.g = 0x90;
	fractol.b = 0x90;
	if (mu < 0.33)
		fractol.b = (fractol.b % x * y)* (mu / 0.33);
	else if (mu < 0.66)
	{
		fractol.r = (fractol.r % (x + y)) * ((mu - 0.33) / 0.33);
		fractol.g = (fractol.g % (x + y)) * ((mu - 0.33) / 0.33);
	}
	else
	{
		fractol.r = (fractol.r % (x + y)) * mu;
		fractol.g = (fractol.g % (x + y)) * ((mu - 0.66) / 0.34);
	}
	color = (fractol.r << 24) | (fractol.g << 16) | (fractol.b << 8) | 255;
	mlx_put_pixel(image, x, y, color);
}

void display_mandelbrot(mlx_t *mlx, mlx_image_t *image, t_fractol fractol)
{
    int	x;
	int	y;
	int	iter;

	x = 0;
	while(x++ < (int)image->width)
	{
		y = 0;
		while(y++ < (int)image->height)
		{
			iter = mandelbrot(
				fractol.xmin + x * (fractol.xmax - fractol.xmin) / (image->width - 1),
				fractol.ymin + y * (fractol.ymax - fractol.ymin) / (image->height - 1),
				fractol.max_iter);
			calculate_color(image, x, y, iter, fractol);
		}
	}

    // Exibir a imagem na janela
    mlx_image_to_window(mlx, image, 0, 0);
}
