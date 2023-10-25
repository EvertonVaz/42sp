/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:01:11 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/23 17:29:41 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_fractol(t_fractol *fractol, int nargs, char **args)
{
	fractol->name = ft_strtolower(args[1]);
	if (fractol->name == NULL)
		fractol->name = "error";
	fractol->argc = nargs;
	fractol->height = 800;
	fractol->width = 800;
	fractol->max_iter = 100;
	fractol->xmax = 1.0;
	fractol->xmin = -2.0;
	fractol->ymax = 1.5;
	fractol->ymin = -1.5;
	fractol->x = 0;
	fractol->y = 0;
	fractol->ccolor = 1;
	fractol->active = 0;
	if (ft_strcmp(fractol->name, "julia") == 0 && fractol->argc == 4)
	{
		fractol->xmax = 2.0;
		fractol->creal = ft_atof(args[2]);
		fractol->cimag = ft_atof(args[3]);
	}
}

char	*change_fractol(t_fractol *st)
{
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_1))
		return("mandelbrot");
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_2))
		return("julia");
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_3))
		return("burn");
	if (mlx_is_key_down(st->mlx, MLX_KEY_KP_4))
		return("tricorn");
	return (st->name);
}

void	select_fractol(t_fractol *st)
{
	st->name = change_fractol(st);
	if (ft_strcmp(st->name, "mandelbrot") == 0)
		return (display_mandelbrot(st));
	if (ft_strcmp(st->name, "julia") == 0)
		return (display_julia(st));
	if (ft_strcmp(st->name, "burn") == 0)
		return (display_burning_ship(st));
	if (ft_strcmp(st->name, "tricorn") == 0)
		return (display_tricorn(st));
}
