/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:18:22 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/09 13:08:25 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_image(t_mlx *mlx, int x, int y)
{
	if (x >= 0 && x < 2880 && y >= 0 && y < 1620)
		mlx->data[x + y * 2880] = mlx_get_color_value(mlx->mlx, 0xFF00FF);
}

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
	ft_image(mlx, x, y);
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
		ft_image(mlx, mlx->xo, mlx->yo);
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
