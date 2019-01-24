/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:44 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/01/23 17:45:50 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int		ft_edited_sqrt(int nb)
{
	int i;

	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int		ft_pow(int nb, int pow)
{
	int res;

	res = 1;
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	while (pow > 0)
	{
		res *= nb;
		pow--;
	}
	return (res);
}

void	ft_iso(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->row)
	{
		y = 0;
		while (y < mlx->col)
		{
			mlx->points[x][y].xo = (mlx->points[x][y].xo - mlx->map[x][y] * mlx->y_offset) * cos(0.523599);
			mlx->points[x][y].yo = -(mlx->points[x][y].yo) + (mlx->points[x][y].xo + mlx->map[x][y] * mlx->y_offset) * sin(0.523599);
			mlx->points[x][y].xo = (mlx->points[x][y].xo + mlx->map[x][y] * mlx->y_offset) * cos(0.523599);
			mlx->points[x][y].yo = (mlx->points[x][y].xo - mlx->map[x][y] * mlx->y_offset) * sin(0.523599) - mlx->points[x][y].yo;
			y++;
		}
		x++;
	}
}
