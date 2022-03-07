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

t_coor	crea_x(t_coor objet)
{
	t_coor	x_vecteur;

	x_vecteur.y = -3.0;
	x_vecteur.x = -(objet.y * x_vecteur.y / objet.x);
	x_vecteur.z = 0.0;
	return (x_vecteur);
}

t_coor	crea_y(t_coor objet, t_coor x_vecteur)
{
	t_coor	y_vecteur;

	y_vecteur.y = -3.0;
	y_vecteur.x = objet.x - (x_vecteur.y * (objet.y - y_vecteur.y) \
	/ x_vecteur.x);
	y_vecteur.z = - (y_vecteur.x * (objet.x - x_vecteur.x) + y_vecteur.y * \
	(objet.y - x_vecteur.y)) / objet.z;
	return (y_vecteur);
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
