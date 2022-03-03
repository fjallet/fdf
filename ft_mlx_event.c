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

int	keyboardpress(int key, t_vars *vars)
{
	printf("%i ", key);
	if (key == ESC)
		close_window(vars);
	if (key == KEY_A || key == KEY_S|| key == KEY_D || key == KEY_W)
		rot_map(key, vars);
	return(0);
}

int	close_window(t_vars *vars)
{
	tabcoor_free(vars->tab, vars->tmap);
	tabpos_free(vars->ptab, vars->tmap);
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

void	rot_x(t_vars *vars, float a)
{
	int		j;
	int		i;
	float	z;
	float	y;
	
	i = 0;
	j = 0;
	while (i <= vars->tmap.x)
	{
		j = 0;
		while (j <= vars->tmap.y)
		{
			z = vars->tab[i][j].z;
			y = vars->tab[i][j].y;
			if (z == 0)
				vars->tab[i][j].z = 0;
			else
				vars->tab[i][j].z = cosf(a) * z - sinf(a) * y;
			if (y == 0)
				vars->tab[i][j].y = 0;
			else
				vars->tab[i][j].y = sinf(a) * z - cos(a) * y;
			printf("z %f %f\n", z, vars->tab[i][j].z);
			printf("y %f %f\n", y, vars->tab[i][j].y);
			j++;
		}
		
		i++;
	}
}

void	rot_z(t_vars *vars, float a)
{
	int		j;
	int		i;
	float	x;
	float	y;
	
	i = 0;
	j = 0;
	while (i <= vars->tmap.x)
	{
		j = 0;
		while (j <= vars->tmap.y)
		{
			x = vars->tab[i][j].x;
			y = vars->tab[i][j].y;
			if (x == 0)
				vars->tab[i][j].x = 0;
			else
				vars->tab[i][j].x = cosf(a) * x - sinf(a) * y;
			if (y == 0)
				vars->tab[i][j].y = 0;
			else
				vars->tab[i][j].y = sinf(a) * x - cos(a) * y;
			//printf("x %f %f\n", x, vars->tab[i][j].x);
			//printf("y %f %f\n", y, vars->tab[i][j].y);
			j++;
		}
		
		i++;
	}
}

int	rot_map(int key, t_vars *vars)
{
	float	a;

	a = 0.01;
	if (key == KEY_W)
		rot_x(vars, a);
	if (key == KEY_D)
		rot_z(vars, a);
	if (key == KEY_S)
		rot_x(vars, -a);
	if (key == KEY_A)
		rot_z(vars, -a);
	//printf("%f",cosf(a));
	return (0);
}
