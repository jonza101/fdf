/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:57:20 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/16 17:59:26 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_begin(t_mlx *mlx)
{
    printf("row: %d         col: %d\n", mlx->row, mlx->col);
    int offset_y = ft_sqrt(mlx->delta_x * mlx->col * mlx->delta_x * mlx->col + mlx->delta_y * mlx->row * mlx->delta_y * mlx->row);
    int offset_x = mlx->delta_x * mlx->col;
    printf("add_y_offset: %f\n", mlx->add_y_offset);
    if (mlx->row > mlx->col || mlx->delta_y < 3)
        mlx->x_b = 960 + mlx->delta_y * mlx->col / 4;
    else if (mlx->row < mlx->col || mlx->delta_y < 3)
        mlx->x_b = 960 - mlx->delta_y * mlx->col / 4;
    else
        mlx->x_b = 960;
    mlx->y_b = 540 - offset_y / 2;
    printf("y_b: %d         x_b: %d\n", mlx->y_b, mlx->x_b);
}
