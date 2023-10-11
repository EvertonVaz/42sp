/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:02:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/11 15:48:37 by egeraldo         ###   ########.fr       */
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
	double		distance;
	int			max_iter;
	int			height;
	int			width;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_fractol;

typedef struct s_colors
{
	int	col1;
	int	col2;
	int	col3;
	int	col4;
	int	col5;
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	double smooth;
}	t_colors;

int				mandelbrot(double real, double imag, t_fractol *st);
void			display_mandelbrot(t_fractol *fractol);
void			initialize_fractol(t_fractol *fractol);
void			mandelbrot_color(int iter, t_fractol *st);
void			up_down(t_fractol *fractol);
void			rigth_left(t_fractol *fractol);
void			zoom_keys(void *param);
void			zoom_scroll(double xdelta, double ydelta, void *param);
void			mouse_click_move(t_fractol *fractol);
int				julia(double real, double imag, t_fractol *st);
void			display_julia(t_fractol *st);
void			julia_color(int iter, t_fractol *st);

#endif