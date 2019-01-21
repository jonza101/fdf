/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:06:57 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/16 18:25:23 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_points(t_mlx *mlx)
{
    int x = 0;
	int y;
	mlx->points = malloc(sizeof(t_point*) * mlx->row + 1);
	while (x < mlx->row + 1)
	{
		y = 0;
		mlx->points[x] = malloc(sizeof(t_point) * mlx->col + 1);
		x++;
	}
}

void    ft_row_col_check(char *map, t_mlx *mlx)
{
    int     col;
    char    **ar;

    mlx->row++;
    col = 0;
    ar = ft_strsplit(map, ' ');
    int x = 0;
    while (ar[x])
    {
        col++;
        x++;
    }
    mlx->col = col;
}

char    **ft_read_map(char *map)
{
    char **ar;

    ar = ft_strsplit(map, ' ');
    return (ar);
}

void    ft_map(t_mlx *mlx)
{
    char    **temp;

    char *line;
    int file = open(mlx->map_file, O_RDONLY);
    mlx->row = 0;
    while (1)
    {
        while (get_next_line(file, &line) == 1)
            ft_row_col_check(line, mlx);
        break ;
    }
    close(file);
    file = open(mlx->map_file, O_RDONLY);
    int x = 0;
    int y;
    mlx->max = -2147483648;
    mlx->map = (int**)malloc(sizeof(int*) * mlx->row);
    while (x < mlx->row)
    {
        y = 0;
        get_next_line(file, &line);
        mlx->map[x] = (int*)malloc(sizeof(int) * mlx->col);
        temp = ft_read_map(line);
        while (y < mlx->col)
        {
            mlx->map[x][y] = ft_atoi(temp[y]);
            if (mlx->map[x][y] > mlx->max)
                mlx->max = mlx->map[x][y];
            y++;
        }
        x++;
    }
    close(file);
}
