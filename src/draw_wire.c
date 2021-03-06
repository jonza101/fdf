/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:58:33 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/09 14:16:46 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_set_temp(int *t_y, t_mlx *mlx)
{
	*t_y = -1;
	mlx->new_x = mlx->x_b + mlx->delta_x;
	mlx->new_row_yo = mlx->yo + mlx->delta_x;
	mlx->new_row_xo = mlx->x_b;
}

void	ft_set_points(int x, int y, t_mlx *mlx)
{
	int t_x;
	int t_y;

	t_x = -1;
	mlx->xo = x;
	mlx->yo = y;
	mlx->new_y = mlx->yo;
	while (++t_x < mlx->row)
	{
		ft_set_temp(&t_y, mlx);
		while (++t_y < mlx->col)
		{
			mlx->points[t_x][t_y].zo = mlx->map[t_x][t_y] * mlx->y_offset;
			mlx->points[t_x][t_y].xo = mlx->xo;
			mlx->points[t_x][t_y].yo = mlx->yo;
			mlx->xo = mlx->new_x;
			mlx->new_x += mlx->delta_x;
		}
		mlx->xo = mlx->x_b;
		mlx->yo = mlx->new_row_yo;
		mlx->new_y = mlx->yo;
	}
	mlx->points[0][0].xo = mlx->points[0][1].xo - mlx->delta_x;
	mlx->points[0][0].yo = mlx->points[0][1].yo;
	mlx->points[0][0].zo = mlx->map[0][0] * mlx->y_offset;
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

void	ft_draw_wire(t_mlx *mlx, int begin)
{
	if (begin == 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, 2880, 1620);
	}
	ft_draw_right(mlx);
	ft_draw_left(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
