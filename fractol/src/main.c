/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/16 18:32:21 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	args_error()
{
	write(1, "Welcome to egeraldo fractal's\n", 31);
	write(1, "\nUSAGE:\n", 8);
	write(1, "\t./fractol [fractal name][params]\n", 34);
	write(1, "\nEXAMPLES:\n", 11);
	write(1,"\tfractol mandelbrot\t\tMandelbrot fractal\n", 40);
	write(1, "\tfractol julia -0.391 -0.587\tJulia fractal\n", 44);
	// fractol newton			Newton fractal for the polynomial (z^3 - 1)
}

void	ft_hook(void *param)
{
	t_fractol	*p;

	p = param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	rigth_left(p);
	up_down(p);
	mouse_click_move(p);
	zoom_keys(p);
	select_fractol(p);
}

int	check_args(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		return (1);
	if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if(check_args(argc, argv))
	{
		initialize_fractol(&fractol, argc, argv);
		fractol.mlx = mlx_init(fractol.width, fractol.height, fractol.name, true);
		fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
		select_fractol(&fractol);
		mlx_loop_hook(fractol.mlx, ft_hook, &fractol);
		mlx_scroll_hook(fractol.mlx, zoom_scroll, &fractol);
		mlx_loop(fractol.mlx);
		mlx_terminate(fractol.mlx);
	}
	else
		args_error();
	return (EXIT_SUCCESS);
}
