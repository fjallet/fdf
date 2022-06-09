/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:48:33 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/09 18:27:47 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tabcoor_free(t_coor **tab, t_pos tmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tmap.x)
	{
		j = 0;
		while (j < tmap.y)
			j++;
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
	while (i < tmap.x)
	{
		j = 0;
		while (j < tmap.y)
			j++;
		free(tab[i]);
		i++;
	}
	free(tab);
}
