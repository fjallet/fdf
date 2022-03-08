/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by fjallet           #+#    #+#             */
/*   Updated: 2022/03/08 18:04:35 by fjallet          ###   ########.fr       */
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

# define ESC 65307
# define RESET 114
# define KEY_A 97
# define KEY_D 100
# define KEY_W 115
# define KEY_S 119
# define KEY_Q 113
# define KEY_E 101
# define ISO 105
# define PERSPECTIVE 112

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
	t_pos	**ptab;
	t_pos	tmap;
	t_pos	twindow;
	t_pos	rot[2];
	int		proj;
	char	*name;
	float	tplan;
	float	zoom;
}				t_vars;

//fdf.c
void	ft_printstruct(t_vars vars);
void	ft_img(t_vars *vars);
int		main(int argc, char **argv);

//ft_mlx_event.c
int		keyboardpress(int key, t_vars *vars);
int		close_window(t_vars *vars);
int		rot_map(int key, t_vars *vars);
int		render_next_frame(t_vars *vars);

//ft_mlx_event_utils.c
void	rot_x(t_vars *vars, float a);
void	rot_y(t_vars *vars, float a);
void	rot_z(t_vars *vars, float a);
void	ft_reset_perspective(t_vars *vars);

//ft_img_utils.c
void	ft_reset_img(t_vars vars, t_data img);

//ft_putpixel
void	ft_segment(t_pos a, t_pos b, t_vars vars);
void	ft_soussegment(t_pos a, t_pos b, t_vars vars, t_pos s);
void	ft_put_to_img(t_vars vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//tab_utils.c
t_pos	**ft_mallocpos(t_pos tmap);
t_pos	init_taille(void);
void	tabposprint(t_pos **tab, t_pos tmap);

//ft_iso.c
t_pos	ft_proj_iso(t_coor c, t_vars vars);
t_vars	*ft_rempiso(t_vars *vars);

//ft_vect.c
t_coor	crea_vect(t_coor a, t_coor b);
t_coor	crea_d(t_coor point, t_coor objet);
t_coor	crea_x(t_coor objet);
t_coor	crea_y(t_coor objet, t_coor y_vecteur);
t_coor	ortho(t_coor vect);

//ft_point.c
t_coor	crea_p(float tprop, t_coor a);
t_coor	crea_alphap(t_coor A, t_coor a, float t);
t_coor	crea_alpha(float zoom);
t_coor	init_objet(void);

//ft_coord.c
float	ft_scalaire(t_coor a, t_coor b);
float	ft_prop(t_coor u, t_coor P, t_coor alpha, t_coor alphap);
void	ft_remp(t_vars *vars, t_coor *vect);
void	ft_setup(t_vars *vars);

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