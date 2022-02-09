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
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_printstruct(char *name, t_coor objet, t_pos taille, t_data img)
{
	int		**tabint;
	t_coor	**tabstruct;
	t_2d	**tabf;
	t_pos	**tab;
	t_pos	tmap;

	ft_putstr("----0----\n");
	tmap.y = ft_countn(ft_readmap(name), ' ', '\n');
	tmap.x = ft_countn(ft_readmap(name), '\n', '\0');
	printf("x = %i y = %i\n", tmap.x, tmap.y);
	tabint = ft_maptrim(name, tmap);
	//tabstruct = ft_mapstruct(tabint, tmap);
	//tabint_free(tabint, tmap);
	ft_putstr("----1----\n");
	//tabf = ft_setup(tabstruct, name, objet, taille);
	//tabcoor_free(tabstruct, tmap);
	//ft_putstr("----2----\n");
	//tab = ft_posi_pxl(tabf, taille, name);
	//ft_putstr("----3----\n");
	//ft_put_to_img(tab, img, name, taille);
	(void)tabstruct;
	(void)tabf;
	(void)tab;
	(void)objet;
	(void)taille;
	(void)img;
}

void	ft_img(char *name)
{
	t_data	img;
	t_vars	vars;
	t_coor	objet;
	t_pos	taille;

	objet = init_objet();
	taille = init_taille();
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "mlx 42");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	ft_printstruct(name, objet, taille, img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	int		**tabint;
	t_pos	tmap;

	ft_putstr("----0----\n");
	if (argc == 0)
		return (1);
	tmap.y = ft_countn(ft_readmap(argv[1]), ' ', '\n');
	tmap.x = ft_countn(ft_readmap(argv[1]), '\n', '\0');
	printf("x = %i y = %i\n", tmap.x, tmap.y);
	tabint = ft_maptrim(argv[1], tmap);
	if (tabint == NULL)
		return (0);
	tabint_free(tabint, tmap);
	return (0);
}
