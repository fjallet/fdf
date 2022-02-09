/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:13 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 15:05:22 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	crea_vect(t_coor a, t_coor b)
{
	t_coor	ab;

	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	ab.z = b.z - a.z;
	return (ab);
}

t_coor	crea_d(t_coor point, t_coor objet)
{
	point.x = point.x + objet.x;
	point.y = point.y + objet.y;
	point.z = point.z + objet.z;
	return (point);
}

t_coor	crea_y(t_coor objet)
{
	t_coor	y_vecteur;

	y_vecteur.x = 3;
	y_vecteur.y = -(objet.x * y_vecteur.x / objet.y);
	y_vecteur.z = 0;
	return (y_vecteur);
}

t_coor	crea_x(t_coor objet, t_coor y_vecteur)
{
	t_coor	x_vecteur;

	x_vecteur.y = 3;
	x_vecteur.x = objet.x - (y_vecteur.y * (objet.y - x_vecteur.y) \
	/ y_vecteur.x);
	x_vecteur.z = - (x_vecteur.x * (objet.x - y_vecteur.x) + x_vecteur.y * \
	(objet.y - y_vecteur.y) / objet.z);
	return (x_vecteur);
}

t_coor	ortho(t_coor vect)
{
	float	n;

	n = sqrtf(vect.x * vect.x + vect.y * vect.y + vect.z + vect.z);
	vect.x = vect.x / n;
	vect.y = vect.y / n;
	vect.z = vect.z / n;
	return (vect);
}
