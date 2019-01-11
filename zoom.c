/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:17:01 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/11 23:53:53 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_mlx *mlx, int dir)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->delta_y += dir;
	if (mlx->delta_y <= 0)
		mlx->delta_y = 0;
	mlx->delta_x = mlx->delta_y * 1.73;
	mlx->y_offset = mlx->delta_y / 10 * mlx->add_y_offset  /  10;
	ft_set_points(mlx->points[0][0].xo, mlx->points[0][0].yo, mlx);
	ft_draw_wire(mlx);
}

void	ft_height(t_mlx *mlx, int dir)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->add_y_offset += dir;
	mlx->y_offset = mlx->delta_y / 10 * mlx->add_y_offset  /  10;
	ft_set_points(mlx->points[0][0].xo, mlx->points[0][0].yo, mlx);
	ft_draw_wire(mlx);
}