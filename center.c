/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:20:32 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/06 18:44:48 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center(t_mlx *mlx)
{
	int height;
	int width;

	height = ft_abs(mlx->points[0][0].yo - mlx->points[mlx->row - 1][mlx->col - 1].yo);
	width = ft_abs(mlx->points[mlx->row - 1][0].xo - mlx->points[0][mlx->col - 1].xo);

	mlx->cent_x = width / 2 + mlx->points[mlx->row - 1][0].xo;
	mlx->cent_y = height / 2 + mlx->points[0][0].yo;
	draw_circle(mlx->cent_x, mlx->cent_y, mlx);
}
