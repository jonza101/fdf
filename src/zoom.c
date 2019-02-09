/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:17:01 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/09 13:58:35 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_start_zoom(t_mlx *mlx, int *d, double dir)
{
	if (dir < 1)
		*d = -1;
	else
		*d = 1;
	mlx->start_x = mlx->points[0][0].xo;
	mlx->start_y = mlx->points[0][0].yo;
	mlx->start_z = mlx->points[0][0].zo;
}

void	ft_zoom(t_mlx *mlx, double dir)
{
	int x;
	int y;
	int d;

	ft_start_zoom(mlx, &d, dir);
	x = 0;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo += (mlx->points[x][y].xo * dir
				- mlx->start_x * dir) * d;
			mlx->points[x][y].yo += (mlx->points[x][y].yo * dir
				- mlx->start_y * dir) * d;
			mlx->points[x][y].zo += (mlx->points[x][y].zo * dir
				- mlx->start_z * dir) * d;
			y++;
		}
		x++;
	}
	ft_center(mlx);
	ft_draw_wire(mlx, 0);
}

void	ft_height(t_mlx *mlx, int dir)
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
			if (mlx->map[0][0] != mlx->map[x][y])
				mlx->points[x][y].yo -= (dir * mlx->map[x][y] * 0.1);
			y++;
		}
		x++;
	}
	ft_center(mlx);
	ft_draw_wire(mlx, 0);
}
