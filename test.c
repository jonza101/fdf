/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:31:32 by zjeyne-l          #+#    #+#             */
/*   Updated: 2018/12/24 19:00:24 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"

#include <stdio.h>

#include <stdlib.h>

typedef	struct	s_point
{
	int xo;
	int yo;
}				t_point;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
	int 	xo;
	int		yo;

	t_point **points;

	int last_offest;

	int delta_x;
	int delta_y;

	int x_b;
	int y_b;

	int		new_x;
	int		new_y;

	int		new_row_xo;
	int 	new_row_yo;
	int		new_row_x;
	int		new_row_y;


	int		mouse_click_count;
	int 	draw_count;
}				t_mlx;

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int		close(void *param)
{
	exit(0);
	return (0);
}

int		mouse_release(int button, int x, int y, t_mlx *mlx)
{
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
		printf("Scroll Up\n");
	if (button == 5)
		printf("Scroll Down\n");
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
void	ft_draw_line(int x, int y, t_mlx *mlx, int offset, int temp_x, int temp_y)
{
	if (mlx->last_offest != offset)
	{
		y -= offset;
		//x -= offset;
		mlx->last_offest = offset;
	}
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
	//draw_circle(x, y, mlx);
	mlx->xo = x;
	mlx->yo = y;
	if (temp_x >= 0 && temp_y >= 0)
	{
		mlx->points[temp_x][temp_y].xo = x;
		mlx->points[temp_x][temp_y].yo = y;
	}
	draw_circle(mlx->xo, mlx->yo, mlx);
	mlx->mouse_click_count = 0;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	char ar[6] = "009900";
	if (mouse_button_check(button) == 3)
		printf("x: %d		y: %d\n", x, y);
	if (mouse_button_check(button) == 2)
		draw_circle(x, y, mlx);
	if (mouse_button_check(button) == 1)
	{
		mlx->mouse_click_count++;
		// if (mlx->mouse_click_count < 2)
		// {
		// 	mlx->xo = x;
		// 	mlx->yo = y;
		// }
		printf("click %d\n", mlx->mouse_click_count);
		if (mlx->mouse_click_count == 1)
		{
			mlx->xo = x;// + mlx->delta_x;
			mlx->yo = y;// + mlx->delta_y;
			mlx->points[0][0].xo = x;
			mlx->points[0][0].yo = y;

			printf("point xo: %d		point yo: %d\n", mlx->points[0][0].xo, mlx->points[0][0].yo);
			printf("temp_x: %d			temp_y: %d\n\n", 0, 0);

			// int delta_x = x - mlx->xo;
			// int delta_y = y - mlx->yo;
			int new_x = mlx->xo + mlx->delta_x;
			int new_y = mlx->yo + mlx->delta_y;
			mlx->x_b = mlx->xo;
			mlx->y_b = mlx->yo;
			int temp_x = 0;
			int temp_y = 1;
			while (temp_x < 6)
			{
				if (temp_y != 1)
					temp_y = 0;
				mlx->new_row_xo = mlx->xo - mlx->delta_x;
				mlx->new_row_yo = mlx->yo + mlx->delta_y;
				mlx->new_row_x = new_x - ft_abs(new_x - mlx->new_row_xo);
				mlx->new_row_y = new_y + ft_abs(new_y - mlx->new_row_yo);
				while (temp_y < 8)
				{
					// mlx->points[temp_x][temp_y].xo = mlx->xo;
					// mlx->points[temp_x][temp_y].yo = mlx->yo;
					// printf("point xo: %d		point yo: %d\n", mlx->points[temp_x][temp_y].xo, mlx->points[temp_x][temp_y].yo);
					// printf("temp_x: %d			temp_y: %d\n\n", temp_x, temp_y);

					// if (temp_x == 0 && temp_y == 0)
					// {
					// 	printf("A: xo: %d		yo: %d\n", mlx->xo, mlx->yo);
					// 	printf("A: x: %d		y: %d\n\n", new_x, new_y);
					// }

					ft_draw_line(new_x, new_y, mlx, 35, temp_x, temp_y);
					new_x += mlx->delta_x;
					new_y += mlx->delta_y;

					printf("point xo: %d		point yo: %d\n", mlx->points[temp_x][temp_y].xo, mlx->points[temp_x][temp_y].yo);
					printf("temp_x: %d		temp_y: %d\n\n", temp_x, temp_y);

					temp_y++;
				}
				mlx->xo = mlx->new_row_xo;
				mlx->yo = mlx->new_row_yo;
				new_x = mlx->new_row_x;
				new_y = mlx->new_row_y;
				printf("\n");
				temp_x++;
			}

			int flag = 0;
			mlx->xo = mlx->x_b;
			mlx->yo = mlx->y_b;
			//new_x = mlx->x_b - mlx->delta_x;
			//new_y = mlx->y_b + mlx->delta_y;
			new_x = mlx->points[1][0].xo;
			new_y = mlx->points[1][0].yo;
			temp_x = 0;
			while (temp_x < 8)
			{
				temp_y = 0;
				printf("temp_x : %d\n\n", temp_x);
				if (mlx->points[1][temp_x + 1].xo == -1 || mlx->points[1][temp_x + 1].yo == -1)
				{
					//ft_draw_line(new_x, new_y, mlx, 0, -1, -1);
					flag = 1;
				}

				mlx->new_row_xo = mlx->points[0][temp_x + 1].xo;
				mlx->new_row_yo = mlx->points[0][temp_x + 1].yo;
				mlx->new_row_x = mlx->points[1][temp_x + 1].xo;
				mlx->new_row_y = mlx->points[1][temp_x + 1].yo;

				// mlx->new_row_xo = mlx->xo + mlx->delta_x;
				// mlx->new_row_yo = mlx->yo + mlx->delta_y;
				// mlx->new_row_x = new_x + ft_abs(mlx->new_row_xo - new_x);
				// mlx->new_row_y = new_y + ft_abs(mlx->new_row_yo - new_y);

				printf("new row xo: %d		new row yo: %d\n", mlx->new_row_xo, mlx->new_row_yo);
				printf("new row x: %d		new row y: %d\n\n", mlx->new_row_x, mlx->new_row_y);

				while (temp_y < 6)
				{
					// if (temp_x == 0 && temp_y == 0)
					// {
					// 	printf("B: xo: %d		yo: %d\n", mlx->xo, mlx->yo);
					// 	printf("B: x: %d		y: %d\n\n", new_x, new_y);
					// }
					ft_draw_line(new_x, new_y, mlx, 0, -1, -1);

					if (mlx->points[temp_y + 1][temp_x].xo == -1 || mlx->points[temp_y + 1][temp_x].yo == -1)
						break ;

					new_x = mlx->points[temp_y + 1][temp_x].xo;
					new_y = mlx->points[temp_y + 1][temp_x].yo;

					printf("new x: %d		new y: %d\n", new_x, new_y);
					
					// new_x -= mlx->delta_x;
					// new_y += mlx->delta_y;
					temp_y++;
				}
				mlx->xo = mlx->new_row_xo;
				mlx->yo = mlx->new_row_yo;
				new_x = mlx->new_row_x;
				new_y = mlx->new_row_y;

				printf("new xo: %d		new yo: %d\n\n\n", mlx->xo, mlx->yo);

				if (flag == 1)
					break ;
				temp_x++;
			}
			// mlx->xo = mlx->x_b;
			// mlx->yo = mlx->y_b;
			// printf("B: xo: %d		yo: %d\n", mlx->xo, mlx->yo);
			// printf("B: x: %d		y: %d\n\n", mlx->xo, mlx->yo - 75);
			//ft_draw_line(mlx->xo, mlx->yo - 75, mlx, 0);
		}
	}
	return (0);
}

int mouse_move(int x, int y, t_mlx *mlx)
{
	// printf("x: %d		y: %d\n", x, y);
	return (0);
}

int key_release(int keycode, void *param)
{
	printf("%d realease\n", keycode);
	return (0);
}

int key_press(int keycode, void *param)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		close((void*)0);
	return (0);
}

int 	main(int argc, char const *argv[])
{
	void	*win_mlx;
	void	*win;
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	
	int x = 0;
	int y;
	mlx->points = malloc(sizeof(t_point*) * 10);
	while (x < 10)
	{
		y = 0;
		mlx->points[x] = malloc(sizeof(t_point) * 10);
		while (y < 10)
		{
			mlx->points[x][y].xo = -1;
			mlx->points[x][y].yo = -1;
			y++;
		}
		x++;
	}

	mlx->delta_x = 78;
	mlx->delta_y = 45;
	
	win_mlx = mlx_init();
	win = mlx_new_window(win_mlx, 1750, 1400, "TEST");
	mlx->mlx = win_mlx;
	mlx->win = win;
	mlx->mouse_click_count = 0;
	mlx->draw_count = 0;

	mlx_hook(win, 2, 1, key_press, (void*)0);
	mlx_hook(win, 3, 2, key_release, (void*)0);
	mlx_hook(win, 17, 3, close, (void*)0);
	//mlx_hook(win, 6, 4, mouse_move, mlx);
	mlx_hook(win, 4, 5, mouse_press, mlx);
	//mlx_hook(win, 5, 6, mouse_release, mlx);

	mlx_loop(win_mlx);
}
