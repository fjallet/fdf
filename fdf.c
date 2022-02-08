/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:07:30 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/08 17:32:12 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int key, t_vars *vars)
{
	if (key == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	ft_img(void)
{
	t_data	img;
	t_vars	vars;
	t_pos	a;
	t_pos	b;
	int		e2;

	a.x = 50;
	a.y = 50;
	b.x = 1500;
	b.y = 100;
	e2 = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "mlx 42");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	ft_segment(a, b, img, e2);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
}

int	main(void)
{
	ft_img();
	return (0);
}
