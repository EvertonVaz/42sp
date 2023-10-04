// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/fractol.h"

void	initialize_fractol(t_fractol *fractol)
{
	fractol->height = 800;
	fractol->width = 800;
	fractol->max_iter = 1000;
	fractol->xmax = 1.0;
	fractol->xmin = -2.0;
	fractol->ymax = 1.5;
	fractol->ymin = -1.5;
	fractol->r = 0;
	fractol->g = 0;
	fractol->b = 0;
}


int main() {
    mlx_t *mlx;
    mlx_image_t *image;
    t_fractol fractol;

    initialize_fractol(&fractol);
    if (!(mlx = mlx_init(fractol.width, fractol.height, "Mandelbrot", true))) {
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }

    if (!(image = mlx_new_image(mlx, fractol.width, fractol.height))) {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return EXIT_FAILURE;
    }

    // Chamar a função para desenhar o fractal na imagem
    display_mandelbrot(mlx, image, fractol);

    // Exibir o fractal na janela
    // draw_fractol(image);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
