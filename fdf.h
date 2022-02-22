/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/09 17:58:22 by fjallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <math.h>

# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_coor	**tab;
	t_pos	tmap;
	t_coor	objet;
	t_pos	twindow;
	t_pos	vert;
	t_pos	horz;
}				t_vars;

//fdf.c
void	ft_printstruct(t_vars vars);
void	ft_img(t_vars *vars);
int		main(int argc, char **argv);

//ft_mlx_event.c
int		close_window(int key, t_vars *vars);
int		mouse_hook(int x, int y, t_vars *vars);

//ft_putpixel
int		ft_segment(t_pos a, t_pos b, t_data img, t_pos taille);
void	ft_soussegment(t_pos a, t_pos b, t_data img, t_pos s);
void	ft_put_to_img(t_pos **tabstruct, t_data img, t_pos tmap, t_pos taille);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//tab_utils.c
t_pos	**ft_mallocpos(t_pos tmap);
t_pos	init_taille(void);

//ft_vect.c
t_coor	crea_vect(t_coor a, t_coor b);
t_coor	crea_d(t_coor point, t_coor objet);
t_coor	crea_y(t_coor objet);
t_coor	crea_x(t_coor objet, t_coor y_vecteur);
t_coor	ortho(t_coor vect);

//ft_point.c
t_coor	crea_p(t_pos t, t_coor u, t_coor v, t_coor a);
t_coor	crea_alphap(t_coor a, float t);
t_coor	crea_alpha(t_coor u, t_coor o);
t_coor	init_objet(void);

//ft_coord.c
float	res_equa(t_coor A, t_coor a, t_coor u, t_coor v);
float	ft_scalaire(t_coor a, t_coor b);
float	ft_prop(t_coor u, t_coor P, t_coor alpha, t_coor alphap);
t_pos	**ft_remp(t_coor **tab, t_pos tmap, t_coor *vect, t_pos taille);
t_pos	**ft_setup(t_coor **tab, t_pos tmap, t_coor objet, t_pos taille);

//ft_split
t_coor	*ft_splitcoor(char *s, char c, int l, t_pos tmap);

//fdf_utils
int		ft_atoi(const char *str);
t_pos	ft_count(char *name);

//free
void	tabcoor_free(t_coor **tab, t_pos tmap);
void	tabpos_free(t_pos **tab, t_pos tmap);

//print
void	ft_putchar(char c);
void	ft_putstr(char *str);

//newmaptrim
t_coor	**ft_maptrim(char *name, t_pos tmap);
t_coor	**ft_mapstruct(int **tab, t_pos tmap);
t_coor	**ft_malloc_coor(t_pos tmap);
char	*ft_readmap(char *name);

//gnl
size_t	ft_strlen(char *s);
size_t	ft_strchrlen(char *s, char c);
char	*ft_strjoin(char *old, char *src);
char	*ft_strtrim1(char *old);
char	*ft_strtrim2(char *old);
char	*ft_strdup(char *s1);
size_t	ft_strchr(char *s, char c);
char	*get_next_line(int fd, int id);
int		ft_endfree(char *rst);

#endif