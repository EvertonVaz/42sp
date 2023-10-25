/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:02:31 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/25 09:41:27 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../.lib/MLX42/include/MLX42/MLX42.h"
# include "../.lib/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractol
{
	char		*name;
	int			argc;
	mlx_image_t	*img;
	mlx_t		*mlx;
	uint32_t	x;
	uint32_t	y;
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
	double		ccolor;
	bool		active;
}				t_fractol;

typedef struct s_colors
{
	int			col1;
	int			col2;
	int			col3;
	int			col4;
	int			col5;
	int			r1;
	int			g1;
	int			b1;
	int			r2;
	int			g2;
	int			b2;
	double		smooth;
}				t_colors;

void			up_down(t_fractol *fractol);
void			rigth_left(t_fractol *fractol);
void			zoom_keys(void *param);
void			zoom_scroll(double xdelta, double ydelta, void *param);
void			mouse_click_move(t_fractol *fractol);
void			mouse_moviment(t_fractol *st);
double			ft_atof(char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strtolower(char *str);
void			change_color(t_fractol *st);
void			init_color(t_colors *colors);
void			initialize_fractol(t_fractol *fractol, int nargs, char **args);
int				interpolate_color(int c1, int c2, t_fractol *st, t_colors c);
void			display_mandelbrot(t_fractol *fractol);
void			display_julia(t_fractol *st);
void			display_burning_ship(t_fractol *st);
void			display_tricorn(t_fractol *st);
void			select_fractol(t_fractol *st);

#endif