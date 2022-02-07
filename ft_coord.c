/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:31 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/07 16:13:07 by fjallet          ###   ########.fr       */
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
	p = ft_scalaire(u, palpha) / ft_scalaire(u, palphap);
	return (p);
}
