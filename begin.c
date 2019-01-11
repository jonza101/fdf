/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:57:20 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/11 23:40:37 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_begin(t_mlx *mlx)
{
    printf("row: %d         col: %d\n", mlx->row, mlx->col);
    int offset = ft_sqrt(mlx->row * mlx->row + mlx->col * mlx->col);
    printf("offset: %d\n", offset);
    mlx->x_b = 1150;// - offset;// * mlx->delta_x;
    mlx->y_b = 0;//offset;// * mlx->delta_y;
}

void    ft_offset(t_mlx *mlx)
{

}
