/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maptrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:11:13 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 18:32:18 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**ft_maptrim(char *name, t_pos tmap)
{
	int		i;
	char	*res;
	int		**tab;
	int		fd;

	i = 0;
	res = "ah";
	fd = open(name, O_RDONLY);
	tab = malloc (sizeof(int **) * ((tmap.x)));
	if (!tab)
		return (NULL);
	while (res != NULL)
	{
		res = get_next_line(fd);
		if (res == NULL)
			break ;
		tab[i] = ft_splitnum(res, ' ');
		if (tab[i] == NULL)
			return (0);
		i++;
		free(res);
	}
	close(fd);
	return (tab);
}

t_coor	**ft_mapstruct(int **tab, t_pos tmap)
{
	t_coor	**tabstruct;
	int		i;
	int		j;

	i = 0;
	tabstruct = ft_malloc_coor(tmap);
	j = 0;
	while (i < tmap.x)
	{
		j = 0;
		while (j < tmap.y)
		{
			tabstruct[i][j].x = j;
			tabstruct[i][j].y = i;
			tabstruct[i][j].z = tab[i][j];
			j++;
		}
		i++;
	}
	ft_putstr("map_struct\n");
	return (tabstruct);
}

t_coor	**ft_malloc_coor(t_pos tmap)
{
	int		i;
	t_coor	**tabstruct;

	i = 0;
	tabstruct = malloc(sizeof(t_coor **) * tmap.x);
	while (i <= tmap.x)
	{
		tabstruct[i] = malloc(sizeof(t_coor *) * tmap.y);
		i++;
	}
	ft_putstr("ft_malloc_coor\n");
	return (tabstruct);
}

char	*ft_readmap(char *name)
{
	int		bs;
	int		temoin;
	char	*str;
	char	buf[11];
	int		fd;

	bs = 10;
	temoin = bs;
	str = NULL;
	fd = open(name, O_RDONLY);
	while (temoin == bs)
	{
		bs = read(fd, buf, 10);
		if (bs < 0 || fd < 0 || fd > 1024)
			return (NULL);
		buf[bs] = '\0';
		str = ft_strjoin(str, buf);
	}
	close(fd);
	return (str);
}
