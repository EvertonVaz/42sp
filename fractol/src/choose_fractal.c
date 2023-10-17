/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/17 19:25:14 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_fractol(t_fractol *fractol, int nargs, char **args)
{
	fractol->name = args[1];
	fractol->argc = nargs;
	fractol->height = 800;
	fractol->width = 800;
	fractol->max_iter = 500;
	fractol->xmax = 1.0;
	fractol->xmin = -2.0;
	fractol->ymax = 1.5;
	fractol->ymin = -1.5;
	fractol->x = 0;
	fractol->y = 0;
	if (ft_strcmp(fractol->name, "julia") == 0)
	{
		fractol->xmax = 2.0;
		fractol->creal = ft_atof(args[2]);
		fractol->cimag = ft_atof(args[3]);
	}
}

int	select_fractol(t_fractol *st)
{
	if (ft_strcmp(st->name, "mandelbrot") == 0 && st->argc == 2)
	{
		display_mandelbrot(st);
		return (1);
	}
	if (ft_strcmp(st->name, "julia") == 0 && st->argc == 4)
	{
		display_julia(st);
		return (1);
	}
	return (0);
}
