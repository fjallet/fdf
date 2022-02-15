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

void	ft_printstruct(char *name, t_coor objet, t_pos taille, t_data img)
{
	t_coor	**tabcoor;
	t_pos	**tab;
	t_pos	tmap;

	printf("----0----\n");
	tmap = ft_count(name);
	printf("x = %i y = %i\n", tmap.x, tmap.y);
	tabcoor = ft_maptrim(name, tmap);
	printf("----1----\n");
	tab = ft_setup(tabcoor, tmap, objet, taille);
	printf("----2----\n");
	tabcoor_free(tabcoor, tmap);
	ft_putstr("----3----\n");
	//ft_put_to_img(tab, img, tmap, taille);
	tabpos_free(tab, tmap);
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
	if (argc == 0)
		return (1);
	ft_img(argv[1]);
	return (0);
}
