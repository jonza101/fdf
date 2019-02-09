/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:25:26 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/09 14:11:50 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_temp_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 7)
		mlx->x = 1;
	if (keycode == 8)
		mlx->y = 1;
	if (keycode == 6)
		mlx->z = 1;
	if (keycode == 69 && mlx->x == 1 && mlx->y == 0 && mlx->z == 0)
		ft_rotate_x(mlx, 1);
	if (keycode == 78 && mlx->x == 1 && mlx->y == 0 && mlx->z == 0)
		ft_rotate_x(mlx, -1);
	if (keycode == 69 && mlx->y == 1 && mlx->x == 0 && mlx->z == 0)
		ft_rotate_y(mlx, 1);
	if (keycode == 78 && mlx->y == 1 && mlx->x == 0 && mlx->z == 0)
		ft_rotate_y(mlx, -1);
	if (keycode == 69 && mlx->z == 1 && mlx->x == 0 && mlx->y == 0)
		ft_rotate_z(mlx, 1);
	if (keycode == 78 && mlx->z == 1 && mlx->x == 0 && mlx->y == 0)
		ft_rotate_z(mlx, -1);
}

void	ft_start_main(t_mlx *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->z = 0;
}
