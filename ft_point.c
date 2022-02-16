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

	tprop.x = t.x / 500;
	tprop.y = t.y / 500;
	p.x = a.x + tprop.x * u.x + tprop.y * v.x;
	p.y = a.y + tprop.x * u.y + tprop.y * v.y;
	p.z = a.z + tprop.x * u.z + tprop.y * v.z;
	return (p);
}

t_coor	crea_alphap(t_coor a, float t)
{
	t_coor	alphap;

	alphap.x = a.x * (t + 1);
	alphap.y = a.y * (t + 1);
	alphap.z = a.z * (t + 1);
	return (alphap);
}

t_coor	crea_alpha(t_coor u, t_coor o)
{
	t_coor	alpha;

	alpha.x = o.x + u.x;
	alpha.y = o.y + u.y;
	alpha.z = o.z + u.z;
	return (alpha);
}

t_coor	init_objet(void)
{
	t_coor	o;

	o.x = 10;
	o.y = 10;
	o.z = -10;
	return (o);
}
