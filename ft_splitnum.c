/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:50:40 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/02 11:50:45 by fjallet          ###   ########.fr       */
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

static size_t	ft_countw(char const *s, char c)
{
	size_t	i;
	size_t	t;
	size_t	count;
	char	*s_temp;

	i = 0;
	t = 1;
	count = 0;
	s_temp = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			t = 1;
		else if (s[i] != c && t == 1)
		{
			count++;
			t = 0;
		}
		i++;
	}
	return (count);
}

int	*ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		*res;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	res = malloc(sizeof(int) * (ft_countw(s, c) + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			res[j] = ft_atoi(&s[i]);
			i += ft_countchar(&s[i], c, j++);
		}
	}
	return (res);
}
