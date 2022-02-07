/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:14:41 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/07 16:28:01 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	ft_inter_point(t_coor A, float t)
{
	t_coor	ainter;

	ainter.x = A.x * (t + 1);
	ainter.y = A.y * (t + 1);
	ainter.z = A.z * (t + 1);
	return (Ainter);
}

`
{
	t_coor	p;

	p.x = a.x + t.x * u.x + t.y * v.x;
	p.y = a.y + t.x * u.y + t.y * v.y;
	p.z = a.z + t.x * u.z + t.y * v.z;
	return (p);
}
