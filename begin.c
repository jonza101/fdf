/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:57:20 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/23 14:56:38 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_delta(t_mlx *mlx)
{
	mlx->delta_y = 1300 / (mlx->row + mlx->col);
	mlx->delta_x = mlx->delta_y * 1.73;
	if (mlx->max < 15)
		mlx->add_y_offset = mlx->max * 5;
	else
		mlx->add_y_offset = ft_edited_sqrt(mlx->max);
	if (mlx->add_y_offset <= 10)
		mlx->add_y_offset = 15;
	mlx->y_offset = mlx->delta_y / 10 * mlx->add_y_offset / 10;
}

void	ft_begin(t_mlx *mlx)
{
	int offset_y;
	int offset_x;

	offset_x = mlx->delta_x * mlx->col;
	offset_y = ft_sqrt(ft_sqrt(ft_pow(mlx->delta_x * mlx->row, 2) +
						ft_pow(mlx->delta_y * mlx->col, 2)) +
				ft_sqrt(ft_pow(mlx->delta_x * mlx->col, 2) +
						ft_pow(mlx->delta_y * mlx->row, 2)));
	if (mlx->row > mlx->col || mlx->delta_y < 3)
		mlx->x_b = 1440 + mlx->delta_y * mlx->col / 4;
	else if (mlx->row < mlx->col || mlx->delta_y < 3)
		mlx->x_b = 1440 - mlx->delta_y * mlx->col / 4;
	else
		mlx->x_b = 1440;
	mlx->y_b = 2 * offset_y;
	// mlx->x_b = 1440 - mlx->delta_y * mlx->row;
	// mlx->y_b = (offset_y + mlx->y_offset + mlx->add_y_offset) * 1;//mlx->delta_y;
	printf("add y offset: %f			y offset: %f\n", mlx->add_y_offset, mlx->y_offset);
	//printf("x %d		y: %d\n", mlx->x_b, mlx->y_b);
}
