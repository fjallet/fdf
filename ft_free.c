/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:48:33 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 18:01:02 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tabcoor_free(t_coor **tab, t_pos tmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= tmap.x)
	{
		j = 0;
		while (j <= tmap.y)
		{
			//printf("(%f ", tab[i][j].x);
			//printf("%f)", tab[i][j].y);
			printf("%f ", tab[i][j].z);
			j++;
		}
		printf("\n");
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	tabpos_free(t_pos **tab, t_pos tmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= tmap.x)
	{
		j = 0;
		while (j <= tmap.y)
		{
			printf("(%i ", tab[i][j].x);
			printf("%i) ", tab[i][j].y);
			j++;
		}
		printf("\n");
		free(tab[i]);
		i++;
	}
	free(tab);
}
