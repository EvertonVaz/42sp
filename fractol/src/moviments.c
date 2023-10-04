/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:54:49 by egeraldo          #+#    #+#             */
/*   Updated: 2023/10/04 18:59:37 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	moviment_keys(t_fractol *fractol)
{
	double panFactorX = 0.5;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		fractol->ymin += panFactorX;
		fractol->ymax += panFactorX;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		fractol->ymin -= panFactorX;
		fractol->ymax -= panFactorX;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		fractol->xmin += panFactorX;
		fractol->xmax += panFactorX;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		fractol->xmax -= panFactorX;
		fractol->xmin -= panFactorX;
	}
}
