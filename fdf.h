/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:07:55 by zjeyne-l          #+#    #+#             */
/*   Updated: 2018/12/26 15:31:58 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
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

	int			last_offset;

	double		delta_x;
	double		delta_y;

	int			x_b;
	int			y_b;

	int			new_row_xo;
	int			new_row_yo;
	int			new_row_x;
	int			new_row_y;

	int			mouse_click_count;
}				t_mlx;

void	ft_map(t_mlx *mlx);
void	ft_row_col_check(char *map, t_mlx *mlx);
char	**ft_read_map(char *map);
void	ft_draw_line(int x, int y, t_mlx *mlx, int offset, int temp_x, int temp_y);
void	ft_rotate(t_mlx *mlx);

#endif
