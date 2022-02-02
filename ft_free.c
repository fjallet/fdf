/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:48:33 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/02 17:56:11 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	res_free(char **res)
{
	int	i;

	i = 0;
	while (res && res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	tab_free(int **tab, char *name)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= ft_countn(ft_readmap(name), '\n', '\0'))
	{
		j = 0;
		while (j <= ft_countn(ft_readmap(name), ' ', '\n'))
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		free(tab[i]);
		i++;
	}
	free(tab);
}
