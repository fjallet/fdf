/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:29:32 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/09 18:30:13 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_reset_img(t_vars vars, t_data img)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.twindow.x)
	{
		j = 0;
		while (j < vars.twindow.y)
		{
			my_mlx_pixel_put(&img, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}
