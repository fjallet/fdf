/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:40:05 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/09 14:33:41 by fjallet          ###   ########.fr       */
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

	t.x = 1980;
	t.y = 1080;
	return (t);
}

void	tabposprint(t_pos **tab, t_pos tmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= tmap.x)
	{
		j = 0;
		while (j <= tmap.y)
		{
			printf("(%i ", tab[i][j].x);
			printf("%i) ", tab[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_coor	init_coor(void)
{
	t_coor	a;
	
	a.x = 0.0;
	a.y = 0.0;
	a.z = 0.0;
	return (a);
}
