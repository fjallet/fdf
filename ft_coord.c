/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:31 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/09 14:34:12 by fjallet          ###   ########.fr       */
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

void	ft_remp(t_vars *vars, t_coor *vect)
{
	int		i;
	int		j;
	float	res;
	t_coor	alphap;
	
	i = 0;
	vars->ptab = ft_mallocpos(vars->tmap);
	while (i <= vars->tmap.x)
	{
		j = 0;
		while (j <= vars->tmap.y)
		{
			res = vect[2].x / (vars->tab[i][j].x + vars->zoom);
			//printf("%f\n", res);
			alphap = crea_alphap(vars->tab[i][j], vect[2], res);
			//printf("%f %f %f\n", vars->tab[i][j].x, vars->tab[i][j].y, vars->tab[i][j].z);
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

	fov = 2.0;
	vars->zoom = 20.0;
	vars->tplan = 10.0;
	vect[0].x = 0.0;
	vect[0].y = 1.0;
	vect[0].z = 0.0;
	vect[1].x = 0.0;
	vect[1].y = 0.0;
	vect[1].z = -1.0;
	vect[2] = crea_alpha(fov);
	if (vars->ptab != NULL)
		tabpos_free(vars->ptab, vars->tmap);
	ft_remp(vars, vect);
}
