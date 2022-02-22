/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:53:09 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 14:21:50 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int key, t_vars *vars)
{
	printf("%d ", key);
	if (key == 65307)
	{
		tabcoor_free(vars->tab, vars->tmap);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	(void)key;
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	t_data	img;
	//t_pos	trot;

	img.img = mlx_new_image(vars->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	printf("%d %d\n", x, y);
	//trot.x = x;
	//trot.y = y;
	my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
	return (0);
}

int	rot_map(int key, t_vars *vars)
{
	if (key == 97)
		vars.vert.x = 1;
	if (key == 119)
		vars.horz.x = 1;
	if (key == 100)
		vars.vert.y = 1;
	if (key == 115)
		vars.horz.y = 1;
	(void)vars;
	return (0);
}
