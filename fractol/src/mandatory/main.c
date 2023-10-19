/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/19 13:12:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	args_error(void)
{
	write(1, "Welcome to egeraldo fractal's\n", 31);
	write(1, "\nUSAGE:\n", 8);
	write(1, "\t./fractol [fractal name][params]\n", 34);
	write(1, "\nEXAMPLES:\n", 11);
	write(1, "\tfractol mandelbrot\t\tMandelbrot fractal\n", 40);
	write(1, "\tfractol julia -0.391 -0.587\tJulia fractal\n", 44);
}

int	check_args(t_fractol st)
{
	if (ft_strcmp(st.name, "mandelbrot") == 0 && st.argc == 2)
		return (1);
	if (ft_strcmp(st.name, "julia") == 0 && st.argc == 4)
		return (1);
	return (0);
}

void	ft_hook(void *param)
{
	t_fractol	*p;

	p = (t_fractol *)param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	rigth_left(p);
	up_down(p);
	mouse_click_move(p);
	zoom_keys(p);
	mouse_moviment(p);
	change_color(p);
	select_fractol(p);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	mlx_t		*mlx;

	initialize_fractol(&fractol, argc, argv);
	mlx = mlx_init(fractol.width, fractol.height, fractol.name, true);
	if (check_args(fractol))
	{
		fractol.mlx = mlx;
		fractol.img = mlx_new_image(mlx, fractol.width, fractol.height);
		select_fractol(&fractol);
		mlx_scroll_hook(mlx, zoom_scroll, &fractol);
		mlx_loop_hook(mlx, ft_hook, &fractol);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
		args_error();
	return (EXIT_SUCCESS);
}
