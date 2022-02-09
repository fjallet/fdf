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

t_pos	**ft_malloc_pos(char *name)
{
	int		i;
	t_pos	**tab;

	i = 0;
	tab = malloc(sizeof(t_pos **) * ft_countn(ft_readmap(name) \
	, '\n', '\0'));
	while (i <= ft_countn(ft_readmap(name), '\n', '\0'))
	{
		tab[i] = malloc(sizeof(t_pos *) * ft_countn(ft_readmap(name) \
		, ' ', '\n'));
		i++;
	}
	return (tab);
}

t_pos	**ft_posi_pxl(t_2d **tabstruct, t_pos taille, char *name)
{
	int		i;
	int		j;
	t_pos	**tab;

	i = 0;
	j = 0;
	tab = ft_malloc_pos(name);
	while (i <= ft_countn(ft_readmap(name), '\n', '\0'))
	{
		j = 0;
		while (j <= ft_countn(ft_readmap(name), ' ', '\n'))
		{
			tab[i][j].x = tabstruct[i][j].x * taille.x;
			tab[i][j].y = tabstruct[i][j].y * taille.y;
			j++;
		}
		i++;
	}
	//tab2d_free(tabstruct, name);
	return (tab);
}

t_pos	init_taille(void)
{
	t_pos	t;

	t.x = 1080;
	t.y = 1980;
	return (t);
}
