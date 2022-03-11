#include "fdf.h"

void	rot_x(t_vars *vars, float a)
{
	int		j;
	int		i;
	float	z;
	float	y;
	
	i = 0;
	j = 0;
	while (i < vars->tmap.x)
	{
		j = 0;
		while (j < vars->tmap.y)
		{
			z = vars->tab[i][j].z;
			y = vars->tab[i][j].y;
			vars->tab[i][j].y = cosf(a) * y - sinf(a) * z;
			vars->tab[i][j].z = sinf(a) * y + cosf(a) * z;
			j++;
		}
		i++;
	}
}

void	rot_y(t_vars *vars, float a)
{
	int		j;
	int		i;
	float	z;
	float	x;
	
	i = 0;
	j = 0;
	while (i < vars->tmap.x)
	{
		j = 0;
		while (j < vars->tmap.y)
		{
			z = vars->tab[i][j].z;
			x = vars->tab[i][j].x;
			vars->tab[i][j].z = cosf(a) * z - sinf(a) * x;
			vars->tab[i][j].x = sinf(a) * z + cosf(a) * x;
			j++;
		}
		i++;
	}
}

void	rot_z(t_vars *vars, float a)
{
	int		j;
	int		i;
	float	x;
	float	y;
	
	i = 0;
	j = 0;
	while (i < vars->tmap.x)
	{
		j = 0;
		while (j < vars->tmap.y)
		{
			x = vars->tab[i][j].x;
			y = vars->tab[i][j].y;
			vars->tab[i][j].x = cosf(a) * x - sinf(a) * y;
			vars->tab[i][j].y = sinf(a) * x + cosf(a) * y;
			j++;
		}
		
		i++;
	}
}

void	ft_reset_perspective(t_vars *vars)
{
	vars->proj = 1;
	tabcoor_free(vars->tab, vars->tmap);
	vars->tab = ft_maptrim(vars->name, vars->tmap, vars);
	rot_y(vars, M_PI / 2);
	rot_x(vars, M_PI / -16);
	rot_z(vars, -M_PI / 5);
	vars->local = init_coor();
	vars->local.x = 20.0;
}

void	ft_reset_isometrique(t_vars *vars)
{
	vars->proj = 0;
	tabcoor_free(vars->tab, vars->tmap);
	vars->tab = ft_maptrim(vars->name, vars->tmap, vars);
	vars->local = init_coor();
}