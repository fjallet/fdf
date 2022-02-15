/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:40:05 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 17:46:56 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	**ft_mallocpos(t_pos tmap)
{
	int		i;
	t_pos	**tab;

	i = 0;
	tab = malloc(sizeof(t_pos *) * tmap.x);
	while (i <= tmap.x)
	{
		tab[i] = malloc(sizeof(t_pos) * tmap.y);
		i++;
	}
	return (tab);
}

t_pos	init_taille(void)
{
	t_pos	t;

	t.x = 1080;
	t.y = 1980;
	return (t);
}
