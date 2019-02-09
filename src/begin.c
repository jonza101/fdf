/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:57:20 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/09 14:07:25 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_set_delta(t_mlx *mlx)
{
	mlx->delta_x = 2000 / (mlx->row + mlx->col);
	if (mlx->max < 15)
		mlx->add_y_offset = mlx->max * 5;
	else
		mlx->add_y_offset = ft_edited_sqrt(mlx->max);
	if (mlx->add_y_offset <= 10)
		mlx->add_y_offset = 15;
	mlx->y_offset = mlx->delta_x / 10 * mlx->add_y_offset / 10;
}

void	ft_begin(t_mlx *mlx)
{
	int offset_y;
	int offset_x;

	offset_x = mlx->delta_x * mlx->col / 2;
	offset_y = mlx->delta_x * mlx->row / 2;
	mlx->x_b = 1440 - offset_x;
	mlx->y_b = 810 - offset_y;
}
