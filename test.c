/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:31:32 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/16 19:42:53 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int		close_win(void *param)
{
	exit(0);
	return (0);
}

int		mouse_button_check(int button)
{
	if (button == 1)
	{
		//printf("LMB\n");
		return (1);
	}
	if (button == 2)
	{
		//printf("RMB\n");
		return (2);
	}
	if (button == 3)
	{
		//printf("MMB\n");
		return (3);
	}
	if (button == 4)
	{
		printf("Scroll Up\n");
		return (4);
	}
	if (button == 5)
	{
		printf("Scroll Down\n");
		return (5);
	}
	if (button == 6)
		printf("Scroll Left\n");
	if (button == 7)
		printf("SCroll Right\n");
	return (0);
}

void	draw_circle(int x, int y, t_mlx *mlx)
{
	int radius = 4;
	int c_x = 0;
	int c_y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while (c_y >= 0)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x + c_x, y + c_y, 255 << 16);
		mlx_pixel_put(mlx->mlx, mlx->win, x + c_x, y - c_y, 255 << 16);
		mlx_pixel_put(mlx->mlx, mlx->win, x - c_x, y + c_y, 255 << 16);
		mlx_pixel_put(mlx->mlx, mlx->win, x - c_x, y - c_y, 255 << 16);
		error = 2 * (delta + c_y) - 1;
		if (delta < 0 && error <= 0)
		{
			delta += 2 * ++c_x + 1;
			continue;
		}
		if (delta > 0 && error > 0)
		{
			delta -= 2 * --c_y + 1;
			continue ;
		}
		delta += 2 * (++c_x - c_y--);
	}
}

/*	ONE LINE	*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void	ft_draw_line(int x, int y, t_mlx *mlx, int offset)
{
	y = y - (offset - mlx->last_offset);
	mlx->last_offset = offset;

	int angle_x = ft_abs(x - mlx->xo);
	int angle_y = ft_abs(y - mlx->yo);
	int delta_x;
	int delta_y;
	int error = angle_x - angle_y;

	if (x < mlx->xo)
		delta_x = -1;
	else
		delta_x = 1;
	if (y < mlx->yo)
		delta_y = -1;
	else
		delta_y = 1;
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, (255 << 16) + 255);
	while (mlx->xo != x || mlx->yo != y)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, mlx->xo, mlx->yo, (255 << 16) + 255);
		if (error * 2 > -angle_y)
		{
			error -= angle_y;
			mlx->xo += delta_x;
		}
		else if (error * 2 < angle_x)
		{
			error += angle_x;
			mlx->yo += delta_y;
		}
	}
	mlx->xo = x;
	mlx->yo = y;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (mouse_button_check(button) == 4)
		ft_zoom(mlx, 1);
	if (mouse_button_check(button) == 5)
		ft_zoom(mlx, -1);
	if (mouse_button_check(button) == 3)
		printf("x: %d		y: %d\n", x, y);

	if (mouse_button_check(button) == 2)
		draw_circle(x, y, mlx);
	return (0);
}

int key_release(int keycode, void *param)
{
	printf("%d realease\n", keycode);
	return (0);
}

int key_press(int keycode, t_mlx *mlx)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		close_win((void*)0);
	//	LEFT
	if (keycode == 65363 || keycode == 1751)
		ft_move_hor(mlx, -mlx->delta_y);
	//	RIGHT
	if (keycode == 65361 || keycode == 1734)
		ft_move_hor(mlx, mlx->delta_y);
	//	UP
	if (keycode == 65364 || keycode == 1753)
		ft_move_vert(mlx, -mlx->delta_y);
	//	DOWN
	if (keycode == 65362  || keycode == 1731)
		ft_move_vert(mlx, mlx->delta_y);
	if (keycode == 65453)
		ft_height(mlx, -1);
	if (keycode == 65451)
		ft_height(mlx, 1);
	return (0);
}

int 	main(int argc, char const *argv[])
{
	int file;
	void	*win_mlx;
	void	*win;
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));

	mlx->map_file = argv[1];

	win_mlx = mlx_init();
	win = mlx_new_window(win_mlx, 1920, 1080, "FDF");
	mlx->mlx = win_mlx;
	mlx->win = win;

	ft_map(mlx);
	ft_points(mlx);

	mlx->delta_y = 800 / (mlx->row + mlx->col);
	if (mlx->delta_y < 1)
		mlx->delta_y = 1;
	mlx->delta_x = mlx->delta_y * 1.73;

	if (mlx->max < 15)
		mlx->add_y_offset = mlx->max * 5;
	else
		mlx->add_y_offset = ft_sqrt(mlx->max);
	if (mlx->add_y_offset <= 10)
		mlx->add_y_offset = 15;
	mlx->y_offset = mlx->delta_y / 10 * mlx->add_y_offset  /  10;

	mlx->last_offset = mlx->map[0][0] * mlx->y_offset;

	ft_begin(mlx);

	ft_set_points(mlx->x_b, mlx->y_b, mlx);
	ft_draw_wire(mlx);

	mlx_hook(win, 2, 1, key_press, mlx);
	mlx_hook(win, 3, 2, key_release, (void*)0);
	mlx_hook(win, 17, 3, close_win, (void*)0);
	mlx_hook(win, 4, 5, mouse_press, mlx);

	mlx_loop(win_mlx);
}
