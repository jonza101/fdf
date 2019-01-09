/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:02:57 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/06 18:56:43 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_rotate(t_mlx *mlx)
{
    int x;
    int y;
    double angle = 0.01;

    x = 0;
    while (x < mlx->row)
    {
        y = 0;
        while (y < mlx->col)
        {
            mlx->points[x][y].xo -= mlx->cent_x;
            mlx->points[x][y].yo -= mlx->cent_y;
            mlx->points[x][y].xo = mlx->points[x][y].xo * cos(angle) - mlx->points[x][y].yo * sin(angle);
            mlx->points[x][y].yo = mlx->points[x][y].xo * sin(angle) + mlx->points[x][y].yo * cos(angle);
            y++;
        }
        x++;
    }
    mlx->xo = mlx->points[0][0].xo;
    mlx->yo = mlx->points[0][0].yo;
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
