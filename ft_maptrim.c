/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maptrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:07:47 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/02 18:15:27 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *old, char *src)
{
	size_t	i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(old) + ft_strlen(src) + 1));
	if (!new)
		return (0);
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		new[i + ft_strlen(old)] = src[i];
		i++;
	}
	new[i + ft_strlen(old)] = '\0';
	if (old)
		free(old);
	return (new);
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

int	**map_trim(char *name)
{
	int		i;
	char	**res;
	int		**tab;

	i = 0;
	res = ft_split(ft_readmap(name), '\n');
	tab = malloc (sizeof(int *) * ((ft_strlenspe(res) + 1)));
	if (!tab)
		return (NULL);
	while (res[i])
	{
		tab[i] = ft_splitnum(res[i], ' ');
		i++;
	}
	res_free(res);
	return (tab);
}

/*int	main()
{
	tab_free(map_trim("map1.txt"), "map1.txt");
	return (0);
}*/
