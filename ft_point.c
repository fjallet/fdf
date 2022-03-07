/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:41 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 12:32:15 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	crea_p(t_pos t, t_coor u, t_coor v, t_coor a)
{
	t_coor	p;
	t_2d	tprop;

	tprop.x = t.x / 500.0;
	tprop.y = t.y / 500.0;
	p.x = a.x + tprop.x * u.x + tprop.y * v.x;
	p.y = a.y + tprop.x * u.y + tprop.y * v.y;
	p.z = a.z + tprop.x * u.z + tprop.y * v.z;
	return (p);
}

t_coor	crea_alphap(t_coor a, float t)
{
	t_coor	alphap;

	alphap.x = a.x * (t + 1.0);
	alphap.y = a.y * (t + 1.0);
	alphap.z = a.z * (t + 1.0);
	return (alphap);
}

t_coor	crea_alpha(t_coor u, float fov)
{
	t_coor	alpha;

	alpha.x = u.x * fov;
	alpha.y = u.y * fov;
	alpha.z = u.z * fov;
	return (alpha);
}

t_coor	init_objet(void)
{
	t_coor	o;

	o.x = 50.0;
	o.y = 50.0;
	o.z = -50.0;
	return (o);
}
