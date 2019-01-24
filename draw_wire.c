/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:58:33 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/24 16:11:39 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_points(int x, int y, t_mlx *mlx)
{
	int t_x;
	int t_y;

	t_y = ft_start_points(mlx, x, y, &t_x);
	while (t_x < mlx->row)
	{
		ft_new_row(mlx, t_x, &t_y);
		while (t_y < mlx->col)
		{
			mlx->points[t_x][t_y].xo = mlx->new_x;
			mlx->points[t_x][t_y].zo = mlx->map[t_x][t_y] * mlx->y_offset;
			if (mlx->map[t_x][t_y] != mlx->map[0][0])
				mlx->points[t_x][t_y].yo = mlx->new_y - mlx->points[t_x][t_y].zo;
			else
				mlx->points[t_x][t_y].yo = mlx->new_y;
			mlx->new_x += mlx->delta_x;
			mlx->new_y += mlx->delta_y;	
			t_y++;
		}
		ft_new_row_next(mlx);
		t_x++;
	}
	mlx->points[0][0].xo = mlx->x_b;
	mlx->points[0][0].yo = mlx->y_b;
	//ft_iso(mlx);
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
			ft_draw_line(mlx->points[x][y + 1].xo,
				mlx->points[x][y + 1].yo, mlx);
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
			ft_draw_line(mlx->points[y + 1][x].xo,
				mlx->points[y + 1][x].yo, mlx);
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
