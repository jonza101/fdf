/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:18:22 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/03 16:35:53 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line_start(t_mlx *mlx, int x, int y)
{
	if (x < mlx->xo)
		mlx->delta_x_line = -1;
	else
		mlx->delta_x_line = 1;
	if (y < mlx->yo)
		mlx->delta_y_line = -1;
	else
		mlx->delta_y_line = 1;
	//mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFF00FF);
	if (x >= 0 && x < 2880 && y >= 0 && y < 1620)
			mlx->data[4 * x + 4 * y * 2880] = mlx_get_color_value(mlx->mlx, 0xFF00FF);
}

void	ft_draw_line_end(t_mlx *mlx, int x, int y)
{
	mlx->xo = x;
	mlx->yo = y;
}

void	ft_draw_line(int x, int y, t_mlx *mlx)
{
	int angle_x;
	int angle_y;
	int error;

	angle_x = ft_abs(x - mlx->xo);
	angle_y = ft_abs(y - mlx->yo);
	error = angle_x - angle_y;
	ft_draw_line_start(mlx, x, y);
	while (mlx->xo != x || mlx->yo != y)
	{
		//mlx_pixel_put(mlx->mlx, mlx->win, mlx->xo, mlx->yo, 0xFF00FF);
		if (mlx->xo >= 0 && mlx->xo < 2880 && mlx->yo >= 0 && mlx->yo < 1620)
			mlx->data[4 * mlx->xo + 4 * mlx->yo * 2880] = mlx_get_color_value(mlx->mlx, 0xFF00FF);
		if (error * 2 > -angle_y)
		{
			error -= angle_y;
			mlx->xo += mlx->delta_x_line;
		}
		else if (error * 2 < angle_x)
		{
			error += angle_x;
			mlx->yo += mlx->delta_y_line;
		}
		else
			break ;
	}
	ft_draw_line_end(mlx, x, y);
}
