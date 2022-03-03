/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:50:40 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 18:22:42 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_countchar(char const *s, char c, size_t j)
{
	size_t	i;

	i = j;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

t_coor	*ft_splitcoor(char *s, char c, int l, t_pos tmap)
{
	size_t	i;
	size_t	j;
	t_coor	*tab;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(t_coor) * (tmap.y + 1));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			tab[j].x = (float)l - tmap.x / 2;
			tab[j].y = (float)j - tmap.y / 2;
			tab[j].z = (float)ft_atoi(&s[i]);
			i += ft_countchar(&s[i], c, j++);
		}
	}
	free(s);
	return (tab);
}
