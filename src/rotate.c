/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:11:36 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 19:34:14 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_center(t_mlx *mlx)
{
	mlx->x_cent = mlx->points[mlx->row - 1][0].xo
		+ (mlx->points[0][mlx->col - 1].xo
			- mlx->points[mlx->row - 1][0].xo) / 2;
	mlx->y_cent = mlx->points[0][0].yo
		+ (mlx->points[mlx->row - 1][mlx->col - 1].yo
			- mlx->points[0][0].yo) / 2;
}

void	ft_rotate_z(t_mlx *mlx, int dir)
{
	int		x;
	int		y;
	double	angle;

	x = 0;
	angle = 0.05 * dir;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo = mlx->x_cent
				+ (mlx->points[x][y].xo - mlx->x_cent) * cos(angle)
					- (mlx->points[x][y].yo - mlx->y_cent) * sin(angle);
			mlx->points[x][y].yo = mlx->y_cent
				+ (mlx->points[x][y].xo - mlx->x_cent) * sin(angle)
					+ (mlx->points[x][y].yo - mlx->y_cent) * cos(angle);
			y++;
		}
		x++;
	}
	ft_center(mlx);
	ft_draw_wire(mlx, 0);
}

void	ft_rotate_y(t_mlx *mlx, int dir)
{
	int		x;
	int		y;
	double	angle;

	x = 0;
	angle = 0.05 * dir;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo = mlx->x_cent
				+ (mlx->points[x][y].xo - mlx->x_cent) * cos(angle)
					+ mlx->points[x][y].zo * sin(angle);
			mlx->points[x][y].zo = -(mlx->points[x][y].xo - mlx->x_cent)
				* sin(angle) + mlx->points[x][y].zo * cos(angle);
			y++;
		}
		x++;
	}
	ft_center(mlx);
	ft_draw_wire(mlx, 0);
}

void	ft_rotate_x(t_mlx *mlx, int dir)
{
	int		x;
	int		y;
	double	angle;

	x = 0;
	angle = 0.05 * dir;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].yo = mlx->y_cent
				+ (mlx->points[x][y].yo - mlx->y_cent) * cos(angle)
					+ mlx->points[x][y].zo * sin(angle);
			mlx->points[x][y].zo = -(mlx->points[x][y].yo - mlx->y_cent)
				* sin(angle) + mlx->points[x][y].zo * cos(angle);
			y++;
		}
		x++;
	}
	ft_center(mlx);
	ft_draw_wire(mlx, 0);
}
