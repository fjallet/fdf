/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_event_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:53:09 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 17:56:01 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboardpress(int key, t_vars *vars)
{
	if (key == ESC)
		close_window(vars);
	if (key == KEY_T || key == KEY_Y || key == KEY_U || key == KEY_G || \
	key == KEY_H || key == KEY_J)
		rot_map(key, vars);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_D || key == KEY_A || \
	key == KEY_W || key == KEY_S || key == PLUS || key == MINUS || \
	key == KEY_1 || key == KEY_2)
		trans_map(key, vars);
	if ((key == KEY_Q || key == KEY_E) && vars->proj == 1)
		rot_plan(vars, key);
	if (key == ISO)
		ft_reset_isometrique(vars);
	if (key == PERSPECTIVE)
		ft_reset_perspective(vars);
	if (key == RESET && vars->proj == 0)
		ft_reset_isometrique(vars);
	if (key == RESET && vars->proj == 1)
		ft_reset_perspective(vars);
	return (0);
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
	if (key == KEY_U)
		rot_all(vars, -a, 'x');
	if (key == KEY_T)
		rot_all(vars, a, 'x');
	if (key == KEY_G)
		rot_all(vars, -a, 'z');
	if (key == KEY_J)
		rot_all(vars, a, 'z');
	if (key == KEY_Y)
		rot_all(vars, -a, 'y');
	if (key == KEY_H)
		rot_all(vars, a, 'y');
	return (0);
}

int	trans_map(int key, t_vars *vars)
{
	if (key == KEY_W)
		vars->local.x += 1;
	if (key == KEY_S)
		vars->local.x -= 1;
	if (key == KEY_UP)
		vars->local.z += 1;
	if (key == KEY_DOWN)
		vars->local.z -= 1;
	if (key == KEY_A)
		vars->local.y += 1;
	if (key == KEY_D)
		vars->local.y -= 1;
	if (key == PLUS && vars->propiso < 50)
		vars->propiso += 1;
	if (key == MINUS && vars->propiso > 1)
		vars->propiso -= 1;
	if (key == KEY_1 && vars->hight >= 0.1)
		vars->hight -= 0.1;
	if (key == KEY_2 && vars->hight <= 2)
		vars->hight += 0.1;
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
