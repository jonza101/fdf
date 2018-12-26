/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:02:57 by zjeyne-l          #+#    #+#             */
/*   Updated: 2018/12/26 18:13:04 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void    ft_rotate(t_mlx *mlx)
// {
//     int x;
//     int y;
//     double angle = 0.01;

//     x = 0;
//     while (x < mlx->row)
//     {
//         y = 0;
//         while (y < mlx->col)
//         {
//             // mlx->points[x][y].xo -= 869;
//             // mlx->points[x][y].yo -= 786;
//             mlx->points[x][y].xo = mlx->points[x][y].xo * cos(angle) - mlx->points[x][y].yo * sin(angle);
//             mlx->points[x][y].yo = mlx->points[x][y].xo * sin(angle) + mlx->points[x][y].yo * cos(angle);
//             y++;
//         }
//         x++;
//     }
    // x = 0;
    // mlx->xo = mlx->points[0][0].xo;
    // mlx->yo = mlx->points[0][0].yo;
    // while (x < mlx->row)
    // {
    //     y = 0;
    //     while (y < mlx->col)
    //     {
    //         printf("rot xo: %d      rot yo: %d\n", mlx->xo, mlx->yo);
    //         ft_draw_line(mlx->points[x][y].xo, mlx->points[x][y].yo, mlx, 0, -1, -1);
    //         y++;
    //     }
    //     x++;
    // }
// }