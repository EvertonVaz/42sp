/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:02:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/09 19:12:27 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			x;
	int			y;
	int			xpos;
	int			ypos;
	double		xzoom;
	double		yzoom;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	int			max_iter;
	int			height;
	int			width;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_fractol;

int				mandelbrot(double real, double imag, int max_iter);
void			display_mandelbrot(t_fractol *fractol);
void			initialize_fractol(t_fractol *fractol);
void			calculate_color(mlx_image_t *image, int iter, t_fractol *st);
void			up_down(t_fractol *fractol);
void			rigth_left(t_fractol *fractol);
void			zoom_wheel(t_fractol *fractol);
void			zoom_scroll(double xdelta, double ydelta, void* param);
void			mouse_click_move(t_fractol *fractol);

#endif