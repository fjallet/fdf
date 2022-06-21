/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:30:51 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/21 12:19:12 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_coor	ft_propiso(t_coor c, t_vars vars)
{
	t_coor	a;

	a.x = (c.x + vars.local.x) * vars.propiso;
	a.y = (c.y + vars.local.y) * vars.propiso;
	a.z = (c.z * vars.hight + vars.local.z) * vars.propiso;
	return (a);
}

t_pos	ft_proj_iso(t_coor c, t_vars vars)
{
	t_pos	b;
	t_coor	a;

	a = ft_propiso(c, vars);
	b.x = -sqrt(2) / 2 * (a.x - a.y) + vars.twindow.x / 2;
	b.y = - (sqrtf(2.0 / 3.0) * a.z) + (1 / sqrt(6) * (a.x + a.y)) \
	+ vars.twindow.y / 2;
	return (b);
}

t_vars	*ft_rempiso(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->tmap.x)
	{
		j = 0;
		while (j <= vars->tmap.y - 1)
		{
			vars->ptab[i][j] = ft_proj_iso(vars->tab[i][j], *vars);
			j++;
		}
		i++;
	}
	return (vars);
}
