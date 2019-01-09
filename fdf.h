/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:07:55 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/06 19:35:25 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef	struct	s_point
{
	int			xo;
	int			yo;
}				t_point;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			xo;
	int			yo;

	int			**map;
	const char	*map_file;

	int			row;
	int			col;

	t_point		**points;

	int			cent_x;
	int			cent_y;

	int			last_offset;

	double		delta_x;
	double		delta_y;
	double		y_offset;

	int			x_b;
	int			y_b;

	int			new_row_xo;
	int			new_row_yo;
	int			new_row_x;
	int			new_row_y;
}				t_mlx;

void	ft_map(t_mlx *mlx);
void	ft_row_col_check(char *map, t_mlx *mlx);
char	**ft_read_map(char *map);

void	ft_rotate(t_mlx *mlx);
void	ft_draw_line(int x, int y, t_mlx *mlx, int offset, int temp_x, int temp_y);

void    ft_points(t_mlx *mlx);

void	ft_center(t_mlx *mlx);
int		ft_abs(int value);
void	draw_circle(int x, int y, t_mlx *mlx);

void	ft_draw_wire(t_mlx *mlx);

void	ft_move_hor(t_mlx *mlx, int dir);
void	ft_move_vert(t_mlx *mlx, int dir);

void	ft_zoom(t_mlx *mlx, int dir);
void	ft_set_points(int x, int y, t_mlx *mlx);

#endif
