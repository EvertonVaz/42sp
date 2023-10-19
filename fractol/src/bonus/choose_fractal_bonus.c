/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/19 17:15:16 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

void	initialize_fractol(t_fractol *fractol, int nargs, char **args)
{
	fractol->name = ft_strtolower(args[1]);
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
	fractol->ccolor = 1;
	if (ft_strcmp(fractol->name, "julia") == 0)
	{
		fractol->xmax = 2.0;
		fractol->creal = ft_atof(args[2]);
		fractol->cimag = ft_atof(args[3]);
	}
}

void	select_fractol(t_fractol *st)
{
	if (ft_strcmp(st->name, "mandelbrot") == 0)
		return (display_mandelbrot(st));
	if (ft_strcmp(st->name, "julia") == 0)
		return (display_julia(st));
	if (ft_strcmp(st->name, "burn") == 0)
		return (display_burning_ship(st));
	if (ft_strcmp(st->name, "tricorn") == 0)
		return (display_tricorn(st));
}
