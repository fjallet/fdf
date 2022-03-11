/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:53:09 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/11 16:07:28 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboardpress(int key, t_vars *vars)
{
	//printf("%i\n", key);
	if (key == ESC)
		close_window(vars);
	if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W || \
	key == KEY_Q || key == KEY_E)
		rot_map(key, vars);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT)
		trans_map(key, vars);
	if (key == ISO)
		ft_reset_isometrique(vars);
	if (key == PERSPECTIVE)
		ft_reset_perspective(vars);
	if (key == RESET && vars->proj == 0)
		ft_reset_isometrique(vars);
	if (key == RESET && vars->proj == 1)
		ft_reset_perspective(vars);
	return(0);
}

int	close_window(t_vars *vars)
{
	get_next_line(vars->fd, 2, 1);
	tabcoor_free(vars->tab, vars->tmap);
	tabpos_free(vars->ptab, vars->tmap);
	if (vars->mlx && vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	rot_map(int key, t_vars *vars)
{
	float	a;

	a = M_PI / 32;
	if (key == KEY_E)
		rot_x(vars, a);
	if (key == KEY_D)
		rot_z(vars, a);
	if (key == KEY_Q)
		rot_x(vars, -a);
	if (key == KEY_A)
		rot_z(vars, -a);
	if (key == KEY_W)
		rot_y(vars, a);
	if (key == KEY_S)
		rot_y(vars, -a);
	return (0);
}

int trans_map(int key, t_vars *vars)
{
	if (key == KEY_UP)
		vars->local.z += 1;
	if (key == KEY_DOWN)
		vars->local.z -= 1;
	if (key == KEY_LEFT)
		vars->local.y -= 1;
	if (key == KEY_RIGHT)
		vars->local.y += 1;
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	ft_reset_img(*vars, vars->img);
	if (vars->proj == 0)
		ft_rempiso(vars);
	if (vars->proj == 1)
		ft_setup(vars);
	ft_put_to_img(*vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
