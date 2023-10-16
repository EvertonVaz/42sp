/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/16 18:12:36 by egeraldo         ###   ########.fr       */
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
		fractol->creal = ft_atof(args[2]);
		fractol->cimag = ft_atof(args[3]);
	}
}

/* int	args_error()
{
	write(1, "Welcome to egeraldo fractal's\n", 31);
	write(1, "\nUSAGE:\n", 8);
	write(1, "\t./fractol [fractal name][params]\n", 34);
	write(1, "\nEXAMPLES:\n", 11);
	write(1,"\tfractol mandelbrot\t\tMandelbrot fractal\n", 40);
	write(1, "\tfractol julia -0.391 -0.587\tJulia fractal\n", 44);
	// fractol newton			Newton fractal for the polynomial (z^3 - 1)
	return (0);
} */

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

/* int main(int argc, char **argv)
{
	t_fractol	fractol;

	initialize_fractol(&fractol);
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			return(printf("argumentos invalidos"));
		fractol.creal = ft_atof(argv[2]);
		fractol.cimag = ft_atof(argv[3]);
		display_julia(&fractol);
	}

} */
