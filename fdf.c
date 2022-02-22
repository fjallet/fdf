/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:07:30 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 18:33:07 by fjallet          ###   ########.fr       */
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

void	ft_printstruct(t_vars vars)
{
	t_pos	**tabpos;

	tabpos = ft_setup(vars.tab, vars.tmap, vars.objet, vars.twindow);
	ft_put_to_img(tabpos, vars.img, vars.tmap, vars.twindow);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_destroy_image(vars.mlx, vars.img.img);
	tabpos_free(tabpos, vars.tmap);
}

void	ft_img(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;
	vars->win = mlx_new_window(vars->mlx, vars->twindow.x, vars->twindow.y, "7");
	//ft_printstruct(vars.tab, vars.objet, vars.taille, img);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, close_window, vars);
	mlx_hook(vars->win, 6, 1L << 6, mouse_hook, vars);
	//mlx_hook(vars->win, 2, 1L << 0, rot_map, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 0)
		return (1);
	vars.tmap = ft_count(argv[1]);
	vars.tab = ft_maptrim(argv[1], vars.tmap);
	vars.objet = init_objet();
	vars.twindow = init_taille();
	ft_img(&vars);
	return (0);
}
