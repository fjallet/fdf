/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:40:02 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/11 16:04:39 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_endfree(char *rst)
{
	if (rst)
	{
		free(rst);
		rst = NULL;
	}
	return (1);
}

size_t	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((sizeof(char)) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd, int id, int leak)
{
	int			bs;
	char		*str;
	static char	*rst[4096];
	char		buf[11];

	bs = 10;
	if (leak == 1)
	{
		free(rst[id]);
		return(NULL);
	}
	if (!rst[id])
		rst[id] = NULL;
	while (ft_strchr(rst[id], '\n') == 0 && bs == 10)
	{
		bs = read(fd, buf, 10);
		if (bs < 0 || fd < 0 || fd > 1024)
			return (NULL);
		if (bs == 0 && ft_strlen(rst[id]) == 0 && ft_endfree(rst[id]))
			return (NULL);
		buf[bs] = '\0';
		rst[id] = ft_strjoin(rst[id], buf);
	}
	str = ft_strtrim1(rst[id]);
	rst[id] = ft_strtrim2(rst[id]);
	return (str);
}
