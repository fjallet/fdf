/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:49:55 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/09 18:39:43 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_segment(t_pos a, t_pos b, t_vars vars)
{
	t_pos	s;

	if (vars.proj == 1 && (a.bo == 0 || b.bo == 0))
		return ;
	if (a.x < b.x)
		s.x = 1;
	else
		s.x = -1;
	if (a.y < b.y)
		s.y = 1;
	else
		s.y = -1;
	ft_soussegment(a, b, vars, s);
}

void	ft_soussegment(t_pos a, t_pos b, t_vars vars, t_pos s)
{
	int	dx;
	int	dy;
	int	e2;
	int	e;

	dx = abs(b.x - a.x);
	dy = abs(b.y - a.y);
	if (dx > dy)
		e = dx / 2;
	else
		e = -dy / 2;
	while (a.x != b.x || a.y != b.y)
	{	
		if (0 < a.x && a.x < vars.twindow.x && 0 < a.y && a.y < vars.twindow.y)
			my_mlx_pixel_put(&vars.img, a.x, a.y, 0x000FF000);
		e2 = e;
		if (e2 > -dx)
			e -= dy;
		if (e2 > -dx)
			a.x += s.x;
		if (e2 < dy)
			e += dx;
		if (e2 < dy)
			a.y += s.y;
	}
}

void	ft_put_to_img(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars.tmap.x - 1)
	{
		j = 0;
		while (j < vars.tmap.y - 1)
		{
			ft_segment(vars.ptab[i][j], vars.ptab[i][j + 1], vars);
			ft_segment(vars.ptab[i][j], vars.ptab[i + 1][j], vars);
			j++;
		}
		ft_segment(vars.ptab[i][j], vars.ptab[i + 1][j], vars);
		i++;
	}
	j = 0;
	while (j < vars.tmap.y - 1)
	{
		ft_segment(vars.ptab[i][j], vars.ptab[i][j + 1], vars);
		j++;
	}
}
