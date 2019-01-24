/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:11:36 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/24 16:11:11 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_circle(int x, int y, t_mlx *mlx)
{
	int radius = 5;
	int c_x = 0;
	int c_y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (c_y >= 0)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x + c_x, y + c_y, 255 << 16);
		mlx_pixel_put(mlx->mlx, mlx->win, x + c_x, y - c_y, 255 << 16);
		mlx_pixel_put(mlx->mlx, mlx->win, x - c_x, y + c_y, 255 << 16);
		mlx_pixel_put(mlx->mlx, mlx->win, x - c_x, y - c_y, 255 << 16);
		error = 2 * (delta + c_y) - 1;
		if (delta < 0 && error <= 0)
		{
			delta += 2 * ++c_x + 1;
			continue;
		}
		if (delta > 0 && error > 0)
		{
			delta -= 2 * --c_y + 1;
			continue ;
		}
		delta += 2 * (++c_x - c_y--);
	}
}

void	ft_center(t_mlx *mlx)
{
	mlx->x_cent = mlx->points[mlx->row - 1][0].xo + (mlx->points[0][mlx->col -1].xo - mlx->points[mlx->row - 1][0].xo) / 2;
	mlx->y_cent = mlx->points[0][0].yo + (mlx->points[mlx->row - 1][mlx->col - 1].yo - mlx->points[0][0].yo) / 2;
	draw_circle(mlx->x_cent, mlx->y_cent, mlx);
}

void	ft_rotate_z(t_mlx *mlx, int dir)
{
	int x;
	int y;
	double angle;

	x = 0;
	angle = 0.05 * dir;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo = mlx->x_cent + (mlx->points[x][y].xo - mlx->x_cent) * cos(angle) - (mlx->points[x][y].yo - mlx->y_cent) * sin(angle);
			mlx->points[x][y].yo = mlx->y_cent + (mlx->points[x][y].xo - mlx->x_cent) * sin(angle) + (mlx->points[x][y].yo - mlx->y_cent) * cos(angle);
			y++;
		}
		x++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_center(mlx);
	ft_draw_wire(mlx);
}

void	ft_rotate_y(t_mlx *mlx, int dir)
{
	int x;
	int y;
	double angle;

	x = 0;
	angle = 0.05 * dir;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo = mlx->points[x][y].xo * cos(angle) + mlx->points[x][y].zo * sin(angle);
			mlx->points[x][y].zo = -(mlx->points[x][y].xo - mlx->x_cent) * sin(angle) + mlx->points[x][y].zo * cos(angle);
			y++;
		}
		x++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_center(mlx);
	ft_draw_wire(mlx);
}

void	ft_rotate_x(t_mlx *mlx, int dir)
{
	int x;
	int y;
	double angle;

	x = 0;
	angle = 0.05 * dir;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].yo = mlx->y_cent + (mlx->points[x][y].yo - mlx->y_cent) * cos(angle) + mlx->points[x][y].zo * sin(angle);
			mlx->points[x][y].zo = -(mlx->points[x][y].yo - mlx->y_cent) * sin(angle) + mlx->points[x][y].zo * cos(angle);
			y++;
		}
		x++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_center(mlx);
	ft_draw_wire(mlx);
}
