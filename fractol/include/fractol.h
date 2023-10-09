/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:02:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/10 13:09:41 by egeraldo         ###   ########.fr       */
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
	double		creal;
	double		cimag;
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
void			calculate_color(int iter, t_fractol *st);
void			up_down(t_fractol *fractol);
void			rigth_left(t_fractol *fractol);
void			zoom_keys(void *param);
void			zoom_scroll(double xdelta, double ydelta, void *param);
void			mouse_click_move(t_fractol *fractol);
int				julia(double real, double imag, t_fractol *st);
void			display_julia(t_fractol *st);

#endif