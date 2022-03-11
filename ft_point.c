/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:41 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/11 12:09:19 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	crea_p(float tprop, t_coor a)
{
	t_coor	p;

	p.x = a.x;
	p.y = -tprop;
	p.z = tprop;
	return (p);
}

t_coor	crea_alphap(t_coor A, t_coor a, float t, t_vars *vars)
{
	t_coor	alphap;

	alphap.x = a.x;
	alphap.y = (A.y + vars->local.y) * (t + 1.0);
	alphap.z = (A.z + vars->local.z) * (t + 1.0);
	return (alphap);
}

t_coor	crea_alpha(float zoom)
{
	t_coor	alpha;

	alpha.x = zoom;
	alpha.y = 0.0;
	alpha.z = 0.0;
	return (alpha);
}

t_coor	init_objet(void)
{
	t_coor	o;

	o.x = 50.0;
	o.y = 50.0;
	o.z = -30.0;
	return (o);
}
