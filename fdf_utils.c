/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:52:35 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 17:21:31 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*size_t	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}*/

size_t	ft_strlenspe(char	**str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sig;
	int	i;

	sig = 1;
	i = 0;
	num = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (48 <= str[i] && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sig);
}

int	ft_countn(char *str, char c, char n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i] != n && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_2d	**ft_malloc2d(char *name)
{
	t_2d	**p;
	int		i;

	i = 0;
	p = malloc(sizeof(t_2d **) * ft_countn(ft_readmap(name), '\n', '\0'));
	while (i <= ft_countn(ft_readmap(name), '\n', '\0'))
	{
		p[i] = malloc(sizeof(t_2d *) * ft_countn(ft_readmap(name), ' ', '\n'));
		i++;
	}
	return (p);
}
