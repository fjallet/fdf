/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/08 17:14:12 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coor {
	float	x;
	float	y;
	float	z;
}				t_coor;

typedef struct s_2d {
	float	x;
	float	y;
}				t_2d;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

//ft_putpixel
void	ft_segment(t_pos a, t_pos b, t_data img, int e2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//ft_vect.c
t_coor	crea_vect(t_coor a, t_coor b);
t_coor	crea_d(t_coor point);
t_coor	crea_y(t_coor objet);
t_coor	crea_x(t_coor objet, t_coor y_vecteur);
t_coor	ortho(t_coor vect);

//ft_point.c
t_coor	crea_p(t_2d t, t_coor u, t_coor v, t_coor a);
t_coor	crea_alphap(t_coor a, float t);
t_coor	crea_alpha(t_coor u, t_coor o);

//ft_coord.c
float	res_equa(t_coor A, t_coor a, t_coor u, t_coor v);
float	ft_scalaire(t_coor a, t_coor b);
float	ft_prop(t_coor u, t_coor P, t_coor alpha, t_coor alphap);

//ft_split
char	**ft_split(char *s, char c);
int		*ft_splitnum(char const *s, char c);

//ft_maptrim.c
char	*ft_strjoin(char *old, char *src);
char	*ft_readmap(char *name);
int		**map_trim(char *name);
t_coor	**ft_mapstruct(int **tab, char *name);
t_coor	**ft_mallocstruct(char *name);

//fdf_utils
size_t	ft_strlen(char	*str);
size_t	ft_strlenspe(char	**str);
int		ft_atoi(const char *str);
int		ft_countn(char *str, char c, char n);
t_2d	**ft_malloc2d(char *name);

//free
void	res_free(char **res);
void	tab_free(int **tab, char *name);

#endif