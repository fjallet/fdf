/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:49:55 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 14:01:18 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_segment(t_pos a, t_pos b, t_data img, t_pos taille)
{
	t_pos	s;

	if (a.x < b.x)
		s.x = 1;
	else
		s.x = -1;
	if (a.y < b.y)
		s.y = 1;
	else
		s.y = -1;
	ft_soussegment(a, b, img, s);
	(void)taille;
	return (0);
}

void	ft_soussegment(t_pos a, t_pos b, t_data img, t_pos s)
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
		if (0 <= a.x && a.x <= 1980 && 0 <= a.y && a.y <= 1080)
			my_mlx_pixel_put(&img, a.x, a.y, 0x00FF0000);
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

void	ft_put_to_img(t_pos **tabstruct, t_data img, t_pos tmap, t_pos taille)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tmap.x)
	{
		j = 0;
		while (j < tmap.y)
		{
			ft_segment(tabstruct[i][j], tabstruct[i][j + 1], img, taille);
			ft_segment(tabstruct[i][j], tabstruct[i + 1][j], img, taille);
			j++;
		}
		ft_segment(tabstruct[i][j], tabstruct[i + 1][j], img, taille);
		i++;
	}
	j = 0;
	while (j < tmap.y)
	{
		ft_segment(tabstruct[i][j], tabstruct[i][j + 1], img, taille);
		j++;
	}
}
