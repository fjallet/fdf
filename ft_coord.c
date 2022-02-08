/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:31 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/08 15:19:38 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

float	res_equa(t_coor A, t_coor a, t_coor u, t_coor v)
{
	float	t;

	t = a.x - A.x + u.x * (A.z - a.z) / u.z + v.x * ((A.y - a.y) / v.y + \
	u.y * (A.z - a.z) / u.z / v.y) / \
	(A.x - A.z * u.x / u.z - A.y * v.x / v.y + v.x * A.z * u.y / u.z / v.y);
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
	return (p);
}

t_2d	**ft_remp(t_coor **tab, char *name, t_coor *vect, t_coor alpha)
{
	t_2d	**ptab;
	int		i;
	int		j;
	t_coor	alphap;
	t_coor	p;

	p = crea_p(taille, vect[1], vect[2], alpha);
	i = 0;
	ptab = ft_malloc2d(char *name);
	while (i <= ft_countn(ft_readmap(name), '\n', '\0'))
	{
		j = 0;
		while (j <= ft_countn(ft_readmap(name), ' ', '\n'))
		{
			alphap = crea_alphap(tab[i][j], res_equa(tab[i][j], alpha, u, v));
			ptab[i][j].x = ft_prop(vect[1], p, alpha, alphap);
			ptab[i][j].y = ft_prop(vect[2], p, alpha, alphap);
			j++;
		}
		i++;
	}
	return (ptab);
}

t_2d	**ft_setup(t_coor **tab, char *name, t_coor objet, t_2d taille)
{
	t_coor	vect[3];
	t_coor	alpha;
	t_2d	**ptab;

	vect[0] = objet;
	vect[2] = crea_y(objet);
	vect[1] = crea_x(objet, vect[2]);
	alpha = crea_alpha(ortho(vect[0]), vect[0]);
	ptab = ft_remp(tab, name, vect, alpha);
	return (ptab);
}
