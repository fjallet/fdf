#include "fdf.h"

void	rot_all(t_vars *vars, float a, char c)
{
	int		j;
	int		i;
	
	i = 0;
	j = 0;
	while (i < vars->tmap.x)
	{
		j = 0;
		while (j < vars->tmap.y)
		{
			if (c == 'z')
				rot_switch(&vars->tab[i][j].x, &vars->tab[i][j].y, a);
			if (c == 'y')
				rot_switch(&vars->tab[i][j].z, &vars->tab[i][j].x, a);
			if (c == 'x')
				rot_switch(&vars->tab[i][j].y, &vars->tab[i][j].z, a);
			j++;
		}
		
		i++;
	}
}

void	rot_switch(float *a, float *b, float alpha)
{
	float	ta;
	float	tb;

	ta = *a;
	tb = *b;
	*a = cosf(alpha) * ta - sinf(alpha) * tb;
	*b = sinf(alpha) * ta + cosf(alpha) * tb;
}

void	rot_plan(t_vars *vars, int key)
{
	float	a;

	if (key == KEY_Q)
		a = M_PI / 32;
	else if (key == KEY_E)
		a = M_PI / -32;
	rot_switch(&vars->local.x, &vars->local.y, a);
	rot_all(vars, a, 'z');
}

void	ft_reset_perspective(t_vars *vars)
{
	vars->proj = 1;
	tabcoor_free(vars->tab, vars->tmap);
	vars->tab = ft_maptrim(vars->name, vars->tmap, vars);
	rot_all(vars, (M_PI + M_PI/8) , 'y');
	init_local(vars);
	vars->local.x = 20.0;
}

void	ft_reset_isometrique(t_vars *vars)
{
	vars->proj = 0;
	tabcoor_free(vars->tab, vars->tmap);
	vars->tab = ft_maptrim(vars->name, vars->tmap, vars);
	vars->local = init_coor();
}