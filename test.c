/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:31:32 by zjeyne-l          #+#    #+#             */
/*   Updated: 2018/12/18 20:31:36 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"

#include <stdio.h>

#include <stdlib.h>

typedef	struct s_mlx
{
	void	*mlx;
	void	*win;
	int 	xo;
	int		yo;

	int 	x_c;
	int		y_c;


/*	REFLECTION	*/
/*##################################################################*/

	int		new_x;
	int		new_y;

	int		new_row_xo;
	int 	new_row_yo;
	int		new_row_x;
	int		new_row_y;
	
/*##################################################################*/


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
		printf("LMB\n");
		return (1);
	}
	if (button == 2)
	{
		printf("RMB\n");
		return (2);
	}
	if (button == 3)
	{
		printf("MMB\n");
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
	int radius = 20;
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

/*	OPPOSITE	*/
/*------------------------------------------------------------------*/

void	ft_opp_draw(int x, int y, t_mlx *mlx)
{
	int opp_xo = mlx->xo;
	int opp_yo = mlx->yo;

	int angle_x = ft_abs(x - mlx->xo);
	int angle_y = ft_abs(y - mlx->yo);
	int error = angle_x - angle_y;

	int delta_x;
	int delta_y;

	if (mlx->xo < x)
		delta_x = 1;
	else
		delta_x = -1;
	if (mlx->yo < y)
		delta_y = 1;
	else
		delta_y = -1;
	
	while (mlx->xo != x)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, mlx->xo, mlx->yo, (255 << 16) + 255);
		mlx_pixel_put(mlx->mlx, mlx->win, opp_xo, opp_yo, (255 << 16) + 255);
		if (error * 2 > -angle_y)
		{
			error -= angle_y;
			mlx->xo += delta_x;
			opp_xo -= delta_x;
		}
		if (error * 2 < angle_x)
		{
			error += angle_x;
			mlx->yo += delta_y;
			opp_yo -= delta_y;
		}
	}
	mlx->draw_count++;
	if (mlx->draw_count == 1)
	{
		int temp_x;
		int temp_y;
		mlx->xo = mlx->x_c;
		mlx->yo = mlx->y_c;
		if (delta_x == 1)
			temp_x = mlx->xo + ft_abs(x - mlx->xo);
		else
			temp_x = mlx->xo - ft_abs(x - mlx->xo);
		if (delta_y == 1)
			temp_y = mlx->yo - ft_abs(y - mlx->yo);
		else
			temp_y = mlx->yo + ft_abs(y - mlx->yo);
		mlx_pixel_put(mlx->mlx, mlx->win, temp_x, temp_y, (255 << 16) + 255);
		//printf("nx: %d		ny: %d\n", temp_x, temp_y);
		ft_opp_draw(temp_x, temp_y, mlx);
	}
	mlx->draw_count = 0;
	mlx->mouse_click_count = 0;
}

/*------------------------------------------------------------------*/


/*	PARALLEL	*/
/*==================================================================*/
void	ft_par_draw(int x, int y, t_mlx *mlx)
{
	int xo = mlx->xo;
	int yo = mlx->yo;

	int par_xo = mlx->xo + ft_abs(x - mlx->xo);
	int par_yo = mlx->yo + ft_abs(y - mlx->yo);
	int par_x = par_xo + ft_abs(x - mlx->xo);
	int par_y = par_yo - ft_abs(y - mlx->yo);

	int angle_x = ft_abs(x - mlx->xo);
	int angle_y = ft_abs(y - mlx->yo);
	int error = angle_x - angle_y;
	int delta_x;
	int delta_y;

	if (mlx->xo < x)
		delta_x = 1;
	else
		delta_x = -1;
	if (mlx->yo < y)
		delta_y = 1;
	else
		delta_y = -1;
	
	printf("par_xo: %d		par_yo: %d\n", par_xo, par_yo);
	printf("par_x: %d		par_y: %d\n", par_x, par_y);
	while (mlx->xo != x)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, mlx->xo, mlx->yo, (255 << 16) + 255);
		mlx_pixel_put(mlx->mlx, mlx->win, par_xo, par_yo, (255 << 16) + 255);
		if (error * 2 > -angle_y)
		{
			error -= angle_y;
			mlx->xo += delta_x;
			par_xo += delta_x;
		}
		if (error * 2 < angle_x)
		{
			error += angle_x;
			mlx->yo += delta_y;
			par_yo += delta_y;
		}
	}
	mlx->draw_count++;
	if (mlx->draw_count == 1)
	{
		mlx->xo = xo;
		mlx->yo = yo;
		printf("x: %d		y: %d\n", x, yo + ft_abs(y - yo));
		ft_par_draw(x, yo - ft_abs(y - yo), mlx);
	}
	else
		mlx->draw_count = 0;
	mlx->mouse_click_count = 0;
}
/*==================================================================*/


/*	REFLECTION	*/
/*##################################################################*/
void	ft_refl_draw(int x, int y, t_mlx *mlx)
{
	int angle_x = ft_abs(x - mlx->xo);
	int angle_y = ft_abs(y - mlx->yo);
	int n_xo = mlx->xo;
	int n_x = x;
	int n_yo = mlx->yo;
	int refl_x = mlx->xo;
	int refl_y = mlx->yo;
	int error = angle_x - angle_y;
	int delta_x;
	int delta_y;

	if (mlx->xo < x)
		delta_x = 1;
	else
		delta_x = -1;
	if (mlx->yo < y)
		delta_y = 1;
	else
		delta_y = -1;
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, (255 << 16) + 255);
	while (mlx->xo != x || mlx->yo != y)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, mlx->xo, mlx->yo, (255 << 16) + 255);
		mlx_pixel_put(mlx->mlx, mlx->win, refl_x, refl_y, (255 << 16) + 255);
		if (error * 2 > -angle_y)
		{
			error -= angle_y;
			mlx->xo += delta_x;
			refl_x += delta_x;
		}
		else if (error * 2 < angle_x)
		{
			error += angle_x;
			mlx->yo += delta_y;
			refl_y -= delta_y;
		}
	}
	mlx->draw_count++;
	if (mlx->draw_count == 1)
	{
		if (delta_x == 1)
			mlx->xo += ft_abs(n_x - n_xo);
		else
			mlx->xo -= ft_abs(n_x - n_xo);
		mlx->yo = n_yo;
		mlx->new_x = mlx->xo;
		mlx->new_y = mlx->yo;
		ft_refl_draw(x, y, mlx);
	}
	else
		mlx->draw_count = 0;
	mlx->xo = refl_x;
	mlx->yo = refl_y;
	mlx->mouse_click_count = 0;
}
/*##################################################################*/

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (mouse_button_check(button) == 3)
		printf("x: %d		y: %d\n", x, y);
	if (mouse_button_check(button) == 2)
		draw_circle(x, y, mlx);
	if (mouse_button_check(button) == 1)
	{
		mlx->mouse_click_count++;
		if (mlx->mouse_click_count < 2)
		{
			mlx->xo = x;
			mlx->yo = y;
		}
		printf("click %d\n", mlx->mouse_click_count);
		if (mlx->mouse_click_count == 2)
		{
			/*	OPPOSITE	*/
			/*------------------------------------------------------------------*/
			
			// mlx->x_c = mlx->xo;
			// mlx->y_c = mlx->yo;
			// printf("xo: %d		yo: %d\n", mlx->xo, mlx->yo);
			// printf("x: %d		y: %d\n\n", x, y);
			// ft_opp_draw(x, y, mlx);
			// mlx->xo = mlx->xo + ft_abs(x - mlx->x_c);
			// mlx->yo = mlx->y_c;
			// mlx->x_c = mlx->xo;
			// mlx->y_c = mlx->yo;
			// printf("xo: %d		yo: %d\n", mlx->xo, mlx->yo);
			// printf("x: %d		y: %d\n", x, y);
			// ft_opp_draw(x, y, mlx);

			// printf("xo: %d		yo: %d\n", mlx->xo, mlx->yo);
			// printf("x: %d		y: %d\n", x, y);

			/*------------------------------------------------------------------*/


			/*	REFLECTION	*/
			/*##################################################################*/

			int i = 0;
			int j = 0;
			mlx->new_x = x;
			mlx->new_y = y;
			while (i < 5)
			{
				j = 0;
				mlx->new_row_xo = mlx->xo - ft_abs(mlx->new_x - mlx->xo);
				mlx->new_row_yo = mlx->yo + ft_abs(mlx->new_y - mlx->yo);
				mlx->new_row_x = mlx->xo;
				mlx->new_row_y = mlx->yo;
				// printf("new_row_xo: %d		new_row_yo: %d\n", mlx->new_row_xo, mlx->new_row_yo);
				// printf("new_row_x: %d		new_row_y: %d\n\n", mlx->new_row_x, mlx->new_row_y);
				while (j < 10)
				{
					ft_refl_draw(mlx->new_x, mlx->new_y, mlx);
					j++;
				}
				mlx->xo = mlx->new_row_xo;
				mlx->yo = mlx->new_row_yo;
				mlx->new_x = mlx->new_row_x;
				mlx->new_y = mlx->new_row_y;
				i++;
			}

			/*##################################################################*/
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
