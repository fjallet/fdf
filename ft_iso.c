#include <fdf.h>

t_coor	ft_propiso(t_coor c)
{
	t_coor	a;

	a.x = c.x * 50;
	a.y = c.y * 50;
	a.z = c.z * 50;
	//printf("%f %f %f\n",a.x ,a.y ,a.z);
	return (a);
}

t_pos	ft_proj_iso(t_coor c, t_vars vars)
{
	t_pos	b;
	t_coor	a;

	a = ft_propiso(c);
	b.x = - sqrt(2) / 2 * (a.x -a.y) + vars.twindow.x / 2;
	b.y = - (sqrtf(2.0 / 3.0) * a.z) + (1 /sqrt(6) * (a.x + a.y)) + vars.twindow.y / 2;
	return (b);
}

t_vars	*ft_rempiso(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i <= vars->tmap.x)
	{
		j = 0;
		while (j <= vars->tmap.y)
		{
			vars->ptab[i][j] = ft_proj_iso(vars->tab[i][j], *vars);
			j++;
		}
		i++;
	}
	return (vars);
}