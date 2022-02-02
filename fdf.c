/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:07:30 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/02 18:15:38 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int key, t_vars *vars)
{
	if (key == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

/*int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "mlx 42");
	mlx_pixel_put(vars.mlx, vars.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printtab(t_list **tab)
{
	int		i;
	t_list	*temp;

	while (*tab != NULL)
	{
		i = 0;
		while ((*tab)->content[i])
		{
			printf("%i ", (*tab)->content[i]);
			i++;
		}
		temp = *tab;
		*tab = (*tab)->next;
		printf("/n");
	}
}

/*int	main()
{
	t_list	**tab;

	tab = map_trim("text.txt");
	ft_printtab(tab);
	ft_lstclear(tab, free);
	return (0);
}*/
