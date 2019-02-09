/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjeyne-l <zjeyne-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:56:19 by zjeyne-l          #+#    #+#             */
/*   Updated: 2019/02/08 18:56:17 by zjeyne-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error_mes(void)
{
	ft_putstr("Usage: ./fdf [map]\n");
	exit(0);
}

void	ft_valid_map_error(void)
{
	ft_putstr("Found wrong line length. Exiting.\n");
	exit(0);
}
