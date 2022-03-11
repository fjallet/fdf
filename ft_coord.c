/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:31 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/11 16:59:23 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

float	ft_scalaire(t_coor a, t_coor b)
{
	float	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

float	ft_prop(t_coor u, t_coor P, t_coor alpha, t_coor alphap)
{
	t_coor	palpha;
	t_coor	palphap;
	float	p;

	palpha = crea_vect(P, alpha);
	palphap = crea_vect(P, alphap);
	p = ft_scalaire(u, palphap) / ft_scalaire(u, palpha) / 2;
	return (p);
}

void	ft_boolcoor(t_vars *vars, int i, int j)
{
	t_2d	cosp;

	cosp.x = vars->tab[i][j].x / (pow(vars->tab[i][j].x, 2.0) + pow(vars->tab[i][j].y, 2.0));
	cosp.y = vars->tab[i][j].x / (pow(vars->tab[i][j].x, 2.0) + pow(vars->tab[i][j].z, 2.0));
	if (vars->cos > cosp.x && vars->cos > cosp.y)
		vars->ptab[i][j].bo = 1;
	else
		vars->ptab[i][j].bo = 0;
}

void	ft_remp(t_vars *vars, t_coor *vect)
{
	int		i;
	int		j;
	float	res;
	t_coor	alphap;
	
	i = 0;
	while (i < vars->tmap.x)
	{
		j = 0;
		while (j < vars->tmap.y)
		{
			res = vect[2].x / (vars->tab[i][j].x + vars->local.x);
			//printf("%f\n", res);
			alphap = crea_alphap(vars->tab[i][j], vect[2], res, vars);
			//printf("%f %f %f\n", vars->tab[i][j].x, vars->tab[i][j].y, vars->tab[i][j].z);
			ft_boolcoor(vars, i, j);
			vars->ptab[i][j].x = ((alphap.y + vars->tplan) / (vars->tplan * 2.0)) * vars->twindow.x;
			vars->ptab[i][j].y = ((alphap.z - vars->tplan) / (vars->tplan * -2.0)) * vars->twindow.y;
			j++;
		}
		i++;
	}
	//tabposprint(vars->ptab, vars->tmap);
}

void	ft_setup(t_vars *vars)
{
	t_coor	vect[3];
	float	fov;

	fov = 1.0;
	vars->local.x = 20.0;
	vars->tplan = 20.0;
	vect[0].x = 0.0;
	vect[0].y = 1.0;
	vect[0].z = 0.0;
	vect[1].x = 0.0;
	vect[1].y = 0.0;
	vect[1].z = -1.0;
	vect[2] = crea_alpha(fov);
	init_cos(vars, fov);
	ft_remp(vars, vect);
}
