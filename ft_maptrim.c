/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maptrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:11:13 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/09 18:36:24 by fjallet          ###   ########.fr       */
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

t_coor	**ft_maptrim(char *name, t_pos tmap, t_vars *vars)
{
	int		i;
	char	*res;
	t_coor	**tab;
	int		fd;

	i = 0;
	res = NULL;
	fd = open(name, O_RDONLY);
	tab = malloc(sizeof(t_coor *) * (tmap.x + 1));
	if (!tab)
		return (NULL);
	while (i < tmap.x)
	{
		res = get_next_line(fd, 2, 0);
		if (res == NULL)
			break ;
		tab[i] = ft_splitcoor(res, ' ', i, tmap);
		i++;
	}
	vars->fd = fd;
	close(fd);
	return (tab);
}
