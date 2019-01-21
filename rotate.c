/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:50:52 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/16 19:32:35 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_rotate(t_mlx *mlx, int dir)
{
    int x;
    int y;
    double angle = 0.01 * dir;

    x = 0;
    while (x < mlx->row)
    {
        y = 0;
        while (y < mlx->col)
        {
            // mlx->points[x][y].xo = mlx->points[x][y].xo * cos(angle) - mlx->points[x][y].yo * sin(angle);
            // mlx->points[x][y].yo = mlx->points[x][y].xo * sin(angle) + mlx->points[x][y].yo * cos(angle);
            
            y++;
        }
        x++;
    }
    mlx_clear_window(mlx->mlx, mlx->win);
    ft_draw_wire(mlx);
}
