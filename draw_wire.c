/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:58:33 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/06 20:38:39 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_points(int x, int y, t_mlx *mlx)
{
	mlx->xo = x;
	mlx->yo = y;
	mlx->points[0][0].xo = x;
	mlx->points[0][0].yo = y - mlx->map[0][0] * 2;
	int new_x = mlx->xo + mlx->delta_x;
	int new_y = mlx->yo + mlx->delta_y;
	mlx->x_b = mlx->xo;
	mlx->y_b = mlx->yo;
	int temp_x = 0;
	int temp_y = 1;
	while (temp_x < mlx->row)
	{
		if (temp_y != 1)
			temp_y = 0;
		if (temp_x < mlx->row - 1)
		{
			mlx->new_row_xo = mlx->xo - mlx->delta_x;
			mlx->new_row_yo = mlx->yo + mlx->delta_y;
			mlx->new_row_x = new_x - ft_abs(new_x - mlx->new_row_xo);
			mlx->new_row_y = new_y + ft_abs(new_y - mlx->new_row_yo);
		}
		while (temp_y < mlx->col)
		{
			mlx->points[temp_x][temp_y].xo = new_x;
			mlx->points[temp_x][temp_y].yo = new_y - mlx->map[temp_x][temp_y] * mlx->y_offset;
			new_x += mlx->delta_x;
			new_y += mlx->delta_y;
			temp_y++;
		}
		mlx->xo = mlx->new_row_xo;
		mlx->yo = mlx->new_row_yo;
		new_x = mlx->new_row_x;
		new_y = mlx->new_row_y;
		temp_x++;
	}
}

void	ft_draw_right(t_mlx *mlx)
{
	int x;
	int y;
	x = 0;
	mlx->xo = mlx->points[0][0].xo;
	mlx->yo = mlx->points[0][0].yo;
	while (x < mlx->row)
	{
		y = 0;
		if (x < mlx->row - 1)
		{
			mlx->new_row_xo = mlx->points[x + 1][0].xo;
			mlx->new_row_yo = mlx->points[x + 1][0].yo;
		}
		while (y < mlx->col - 1)
		{
			ft_draw_line(mlx->points[x][y + 1].xo, mlx->points[x][y + 1].yo, mlx, 0, -1, -1);
			y++;
		}
		mlx->xo = mlx->new_row_xo;
		mlx->yo = mlx->new_row_yo;
		x++;
	}
}

void	ft_draw_left(t_mlx *mlx)
{
	int x;
	int y;
	x = 0;
	mlx->xo = mlx->points[0][0].xo;
	mlx->yo = mlx->points[0][0].yo;
	while (x < mlx->col)
	{
		y = 0;
		if (x < mlx->col - 1)
		{
			mlx->new_row_xo = mlx->points[0][x + 1].xo;
			mlx->new_row_yo = mlx->points[0][x + 1].yo;
		}
		while (y < mlx->row - 1)
		{
			ft_draw_line(mlx->points[y + 1][x].xo, mlx->points[y + 1][x].yo, mlx, 0, -1, -1);
			y++;
		}
		mlx->xo = mlx->new_row_xo;
		mlx->yo = mlx->new_row_yo;
		x++;
	}
}

void	ft_draw_wire(t_mlx *mlx)
{
	ft_draw_right(mlx);
	ft_draw_left(mlx);
}
