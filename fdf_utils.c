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

t_pos	ft_count(char *name)
{
	int		i;
	int		count;
	t_pos	tmap;
	char	*str;
	int		fd;

	i = 0;
	count = 0;
	fd = open(name, O_RDONLY);
	str = get_next_line(fd, 1);
	while (str && str[i] != '\0' && str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	free(str);
	tmap.y = count;
	i = 0;
	while (str != NULL && i++ >= 0)
	{
		str = get_next_line(fd, 1);
		free(str);
	}
	tmap.x = i - 1;
	close(fd);
	return (tmap);
}