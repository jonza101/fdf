/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:07:55 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/03 16:07:07 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "get_next_line/get_next_line.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef	struct	s_point
{
	double		xo;
	double		yo;
	double		zo;
}				t_point;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;

	int			xo;
	int			yo;

	int			**map;
	const char	*map_file;

	int			row;
	int			col;

	t_point		**points;

	int			last_offset;

	int			max;

	double		delta_x;
	double		delta_y;
	double		y_offset;
	double		add_y_offset;

	int			delta_x_line;
	int			delta_y_line;

	double		x_b;
	double		y_b;

	int			x_cent;
	int			y_cent;

	double		new_row_xo;
	double		new_row_yo;
	double		new_row_x;
	double		new_row_y;

	double		new_x;
	double		new_y;

	int			x;
	int			y;
	int			z;

	double		start_x;
	double		start_y;
	double		start_z;
}				t_mlx;

void			ft_map(t_mlx *mlx);
void			ft_row_col_check(char *map, t_mlx *mlx);
char			**ft_read_map(char *map);

void			ft_draw_line(int x, int y, t_mlx *mlx);

void			ft_points(t_mlx *mlx);

int				ft_abs(int value);
int				ft_edited_sqrt(int nb);
int				ft_pow(int nb, int pow);

void			ft_begin(t_mlx *mlx);
void			ft_draw_wire(t_mlx *mlx, int begin);
void			ft_set_points(int x, int y, t_mlx *mlx);

void			ft_move_hor(t_mlx *mlx, int dir);
void			ft_move_vert(t_mlx *mlx, int dir);

void			ft_zoom(t_mlx *mlx, double dir);
void			ft_height(t_mlx *mlx, int dir);

int				ft_start_points(t_mlx *mlx, int x, int y, int *t_x);
void			ft_new_row(t_mlx *mlx, int t_x, int *t_y);
void			ft_new_row_next(t_mlx *mlx);
void			ft_set_delta(t_mlx *mlx);

void			ft_center(t_mlx *mlx);

void			ft_rotate_x(t_mlx *mlx, int dir);
void			ft_rotate_y(t_mlx *mlx, int dir);
void			ft_rotate_z(t_mlx *mlx, int dir);

void			ft_temp_key_press(int keycode, t_mlx *mlx);
void			ft_start_main(t_mlx *mlx);

#endif
