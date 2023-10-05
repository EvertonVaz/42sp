// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "../include/fractol.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	initialize_fractol(t_fractol *fractol)
{
	fractol->height = 512;
	fractol->width = 512;
	fractol->max_iter = 300;
	fractol->xmax = 1.0;
	fractol->xmin = -2.0;
	fractol->ymax = 1.5;
	fractol->ymin = -1.5;
	fractol->r = 0;
	fractol->g = 0;
	fractol->b = 0;
}

void	ft_hook(void *param)
{
	t_fractol	*p;

	p = param;
	if (mlx_is_key_down(p->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(p->mlx);
	moviment_keys(p);
	zoom_wheel(p);
	display_mandelbrot(p);
}

int	main(void)
{
	t_fractol	fractol;

	initialize_fractol(&fractol);
	fractol.mlx = mlx_init(fractol.width, fractol.height, "Mandelbrot", true);
	fractol.img = mlx_new_image(fractol.mlx, fractol.width, fractol.height);

	// Chamar a função para desenhar o fractal na imagem
	display_mandelbrot(&fractol);
	mlx_loop_hook(fractol.mlx, ft_hook, &fractol);


	// Exibir o fractal na janela
	// draw_fractol(image);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
