/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:07:30 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/09 18:09:54 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_img(t_vars *vars)
{
	t_data	img;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;
	vars->win = mlx_new_window(vars->mlx, vars->twindow.x, vars->twindow.y, \
	"7");
	img.img = mlx_new_image(vars->mlx, vars->twindow.x, vars->twindow.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	mlx_hook(vars->win, 2, 1L << 0, keyboardpress, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_window, vars);
	vars->img = img;
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 0)
		return (1);
	vars.tmap = ft_count(argv[1]);
	vars.tab = ft_maptrim(argv[1], vars.tmap, &vars);
	vars.ptab = ft_mallocpos(vars.tmap);
	vars.twindow = init_taille();
	vars.proj = 0;
	vars.local = init_coor();
	vars.name = argv[1];
	vars.local = init_coor();
	vars.propiso = 20;
	ft_img(&vars);
	return (0);
}
