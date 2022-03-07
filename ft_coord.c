/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:31 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 14:16:18 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

float	res_equa(t_coor A, t_coor a, t_coor u, t_coor v)
{
	float	t;

	t = (a.x - A.x + u.x * (A.z - a.z) / u.z + v.x * ((A.y - a.y) / v.y + \
	u.y * (A.z - a.z) / u.z / v.y)) / \
	(A.x - A.z * u.x / u.z - A.y * v.x / v.y + v.x * A.z * u.y / (u.z * v.y));
	return (t);
}

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
	//printf("%f ", p);
	return (p);
}

t_pos	**ft_remp(t_coor **tab, t_pos tmap, t_coor *vect, t_pos taille)
{
	t_pos	**ptab;
	int		i;
	int		j;
	t_coor	alphap;
	t_coor	p;

	p = crea_p(taille, vect[2], vect[1], vect[3]);
	i = 0;
	ptab = ft_mallocpos(tmap);
	ft_putstr("ici\n");
	while (i <= tmap.x)
	{
		j = 0;
		while (j <= tmap.y)
		{
			alphap = crea_alphap(crea_vect(vect[0], tab[i][j]), \
			res_equa(crea_vect(vect[0], tab[i][j]), vect[3], \
			vect[1], vect[2]));
			printf("%f %f %f\n", tab[i][j].x, tab[i][j].y, tab[i][j].z);
			//printf("%f %f %f\n", alphap.x, alphap.y, alphap.z);
			ptab[i][j].x = ft_prop(vect[2], p, vect[3], alphap) * taille.x;
			ptab[i][j].y = ft_prop(vect[1], p, vect[3], alphap) * taille.y;
			j++;
		}
		i++;
	}
	tabposprint(ptab, tmap);
	return (ptab);
}

void	ft_setup(t_vars *vars)
{
	t_coor	vect[4];
	float	fov;

	fov = 20;
	vect[0] = vars->objet;
	vect[2] = ortho(crea_x(vars->objet));
	vect[1] = ortho(crea_y(vars->objet, vect[2]));
	vect[3] = crea_alpha(ortho(vect[0]), fov);
	vars->ptab = ft_remp(vars->tab, vars->tmap, vect, vars->twindow);
}
