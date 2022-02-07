/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/07 15:44:41 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coor {
	float	x;
	float	y;
	float	z;
}				t_coor;

typedef struct s_size {
	float	x;
	float	y;
}				t_size;

//ft_vect.c
t_coor	crea_vect(t_coor a, t_coor b);
t_coor	crea_d(t_coor point);
t_coor	crea_y(t_coor objet);
t_coor	crea_x(t_coor objet, t_coor y_vecteur);
t_coor	ortho(t_coor vect);

//ft_point.c
t_coor	ft_inter_point(t_coor A, float t);
t_coor	crea_p(t_size t, t_coor u, t_coor v, t_coor a);

//ft_coord.c
float	res_equa(t_coor A, t_coor a, t_coor u, t_coor v);
float	ft_scalaire(t_coor a, t_coor b);
float	ft_prop(t_coor u, t_coor P, t_coor alpha, t_coor alphap);

//ft_maptrim
char	**ft_split(char *s, char c);
int		*ft_splitnum(char const *s, char c);
char	*ft_strjoin(char *old, char *src);
char	*ft_readmap(char *name);
int		**map_trim(char *name);

//fdf_utils
size_t	ft_strlen(char	*str);
size_t	ft_strlenspe(char	**str);
int		ft_atoi(const char *str);
int		ft_countn(char *str, char c, char n);

//free
void	res_free(char **res);
void	tab_free(int **tab, char *name);

#endif