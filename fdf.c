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

void	ft_printstruct(t_coor **tabc, t_coor objet, t_pos taille, t_data img)
{
	t_pos	**tab;
	t_pos	tmap;

	tab = ft_setup(tabc, tmap, objet, taille);
	tabcoor_free(tabc, tmap);
	ft_put_to_img(tab, img, tmap, taille);
	tabpos_free(tab, tmap);
}

void	ft_img(char *name, t_coor **tab, t_pos ttab)
{
	t_vars	vars;

	vars.ttab = ttab;
	vars.tab = tab;
	vars.objet = init_objet();
	vars.taille = init_taille();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return ;
	vars.win = mlx_new_window(vars.mlx, vars.taille.x, vars.taille.y, "mlx 42");
	//ft_printstruct(vars.tab, vars.objet, vars.taille, img);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	(void)name;
}

int	main(int argc, char **argv)
{
	t_pos	tmap;

	if (argc == 0)
		return (1);
	tmap = ft_count(argv[1]);
	ft_img(argv[1], ft_maptrim(argv[1], tmap), tmap);
	return (0);
}
