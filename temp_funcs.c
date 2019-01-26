/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:25:26 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/25 14:50:18 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_start_points(t_mlx *mlx, int x, int y, int *t_x)
{
	mlx->xo = x;
	mlx->yo = y;
	mlx->points[0][0].xo = x;
	mlx->points[0][0].yo = y - mlx->map[0][0] * mlx->y_offset;
	mlx->new_x = mlx->xo + mlx->delta_x;
	mlx->new_y = mlx->yo + mlx->delta_y;
	mlx->x_b = mlx->xo;
	mlx->y_b = mlx->yo;
	*t_x = 0;
	return (1);
}

void	ft_new_row(t_mlx *mlx, int t_x, int *t_y)
{
	if (*t_y != 1)
		*t_y = 0;
	if (t_x < mlx->row - 1)
	{
		mlx->new_row_xo = mlx->xo - mlx->delta_x;
		mlx->new_row_yo = mlx->yo + mlx->delta_y;
		mlx->new_row_x = mlx->new_x - ft_abs(mlx->new_x - mlx->new_row_xo);
		mlx->new_row_y = mlx->new_y + ft_abs(mlx->new_y - mlx->new_row_yo);
	}
}

void	ft_new_row_next(t_mlx *mlx)
{
	mlx->xo = mlx->new_row_xo;
	mlx->yo = mlx->new_row_yo;
	mlx->new_x = mlx->new_row_x;
	mlx->new_y = mlx->new_row_y;
}

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
