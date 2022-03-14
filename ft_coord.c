/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:31 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/14 17:50:58 by fjallet          ###   ########.fr       */
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

void	ft_remp(t_vars *vars, t_coor alpha)
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
			res = alpha.x / (vars->tab[i][j].x + vars->local.x);
			alphap = crea_alphap(vars->tab[i][j], alpha, res, vars);
			if (vars->tab[i][j].x + vars->local.x < 1.0)
				vars->ptab[i][j].bo = 0;
			else
				vars->ptab[i][j].bo = 1;
			vars->ptab[i][j].x = ((alphap.y + vars->tplan) / (vars->tplan * 2.0)) * vars->twindow.x;
			vars->ptab[i][j].y = ((alphap.z + vars->tplan) / (vars->tplan * 2.0)) * vars->twindow.y;
			j++;
		}
		i++;
	}
}

void	ft_setup(t_vars *vars)
{
	t_coor	alpha;
	float	fov;

	fov = 4;
	vars->tplan = 5.0;
	alpha = crea_alpha(fov);
	ft_remp(vars, alpha);
}
