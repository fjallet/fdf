/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:49:55 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/08 17:31:30 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_segment(t_pos a, t_pos b, t_data img, int e2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e;

	dx = abs(b.x - a.x);
	sx = a.x < b.x ? 1 : -1;
	dy = abs(b.y - a.y);
	sy = a.y < b.y ? 1 : -1;
	e = (dx > dy ? dx : -dy)/2;
	while (a.x != b.x && a.y != b.y)
	{
		my_mlx_pixel_put(&img, a.x, a.y, 0x00FF0000);
		e2 = e;
		if (e2 > -dx)
		{
			e -= dy;
			a.x += sx;
		}
		if (e2 < dy)
		{
			e += dx;
			a.y += sy;
		}
	}
}
