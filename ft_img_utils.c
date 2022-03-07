#include <fdf.h>

void	ft_reset_img(t_vars vars, t_data img)
{
	int	i;
	int	j;

	i =	0;
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