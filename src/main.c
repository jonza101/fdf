/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:31:32 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/09 14:11:44 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 7)
		mlx->x = 0;
	if (keycode == 8)
		mlx->y = 0;
	if (keycode == 6)
		mlx->z = 0;
	return (0);
}

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
	{
		ft_set_points(mlx->x_b, mlx->y_b, mlx);
		ft_draw_wire(mlx, 0);
	}
	if (keycode == 124 || keycode == 2)
		ft_move_hor(mlx, -mlx->delta_x);
	if (keycode == 123 || keycode == 0)
		ft_move_hor(mlx, mlx->delta_x);
	if (keycode == 125 || keycode == 1)
		ft_move_vert(mlx, -mlx->delta_x);
	if (keycode == 126 || keycode == 13)
		ft_move_vert(mlx, mlx->delta_x);
	if (keycode == 27)
		ft_height(mlx, -1);
	if (keycode == 24)
		ft_height(mlx, 1);
	if (keycode == 78 && mlx->x == 0 && mlx->y == 0 && mlx->z == 0)
		ft_zoom(mlx, 0.1);
	if (keycode == 69 && mlx->x == 0 && mlx->y == 0 && mlx->z == 0)
		ft_zoom(mlx, 1);
	ft_temp_key_press(keycode, mlx);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x < 0 || y < 0)
		return (0);
	if (button == 4 && mlx->x == 0 && mlx->y == 0 && mlx->z == 0)
		ft_zoom(mlx, 1);
	if (button == 5 && mlx->x == 0 && mlx->y == 0 && mlx->z == 0)
		ft_zoom(mlx, 0.1);
	if (button == 4 && mlx->x == 1 && mlx->y == 0 && mlx->z == 0)
		ft_rotate_x(mlx, 1);
	if (button == 5 && mlx->x == 1 && mlx->y == 0 && mlx->z == 0)
		ft_rotate_x(mlx, -1);
	if (button == 4 && mlx->y == 1 && mlx->x == 0 && mlx->z == 0)
		ft_rotate_y(mlx, 1);
	if (button == 5 && mlx->y == 1 && mlx->x == 0 && mlx->z == 0)
		ft_rotate_y(mlx, -1);
	if (button == 4 && mlx->z == 1 && mlx->x == 0 && mlx->y == 0)
		ft_rotate_z(mlx, 1);
	if (button == 5 && mlx->z == 1 && mlx->x == 0 && mlx->y == 0)
		ft_rotate_z(mlx, -1);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_mlx	*mlx;

	if (argc != 2)
		ft_error_mes();
	mlx = malloc(sizeof(t_mlx));
	ft_start_main(mlx);
	mlx->map_file = argv[1];
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 2880, 1620, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, 2880, 1620);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &mlx->bpp,
		&mlx->size_line, &mlx->endian);
	ft_map(mlx);
	ft_points(mlx);
	ft_set_delta(mlx);
	ft_begin(mlx);
	ft_set_points(mlx->x_b, mlx->y_b, mlx);
	ft_draw_wire(mlx, 1);
	ft_center(mlx);
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1, key_release, mlx);
	mlx_hook(mlx->win, 4, 2, mouse_press, mlx);
	mlx_hook(mlx->win, 17, 3, close_win, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
