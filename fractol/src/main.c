/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:26 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/11 15:46:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_fractol(t_fractol *fractol)
{
	fractol->height = 800;
	fractol->width = 800;
	fractol->max_iter = 500;
	fractol->xmax = 1.0;
	fractol->xmin = -2.0;
	fractol->ymax = 1.5;
	fractol->ymin = -1.5;
	fractol->x = 0;
	fractol->y = 0;
	fractol->creal = -0.55;
	fractol->cimag = -0.45;
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
	display_julia(p);
}

int	main(void)
{
	t_fractol	fractol;

	initialize_fractol(&fractol);
	fractol.mlx = mlx_init(fractol.width, fractol.height, "Mandelbrot", true);
	fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);
	display_julia(&fractol);
	mlx_loop_hook(fractol.mlx, ft_hook, &fractol);
	mlx_scroll_hook(fractol.mlx, zoom_scroll, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
