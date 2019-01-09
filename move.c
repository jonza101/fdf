/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:57:33 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/06 20:40:15 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move_hor(t_mlx *mlx, int dir)
{
	int x;
	int y;
	x = 0;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo += dir;
			y++;
		}
		x++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_draw_wire(mlx);
}

void	ft_move_vert(t_mlx *mlx, int dir)
{
	int x;
	int y;
	x = 0;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].yo += dir;
			y++;
		}
		x++;
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_draw_wire(mlx);
}
