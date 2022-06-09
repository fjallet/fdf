/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by fjallet           #+#    #+#             */
/*   Updated: 2022/06/09 18:50:45 by fjallet          ###   ########.fr       */
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
# define KEY_T 116
# define KEY_Y 121
# define KEY_U 117
# define KEY_G 103
# define KEY_H 104
# define KEY_J 106
# define KEY_A 97
# define KEY_D 100
# define KEY_W 115
# define KEY_S 119
# define KEY_Q 113
# define KEY_E 101
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define ISO 105
# define PERSPECTIVE 112
# define PLUS 65451
# define MINUS 65453

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
	int bo;
}				t_pos;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_coor	**tab;
	t_coor	local;
	t_pos	**ptab;
	t_pos	tmap;
	t_pos	twindow;
	t_pos	rot[2];
	float	scale;
	int		proj;
	char	*name;
	float	tplan;
	float	cos;
	int		fd;
	int		propiso;
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
int 	trans_map(int key, t_vars *vars);

//ft_mlx_event_utils.c
void	rot_all(t_vars *vars, float a, char c);
void	rot_switch(float *a, float *b, float alpha);
void	rot_plan(t_vars *vars, int key);
void	ft_reset_perspective(t_vars *vars);
void	ft_reset_isometrique(t_vars *vars);

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
//void	tabcoorzprint(t_coor **tab, t_pos tmap);
//void	tabposprint(t_pos **tab, t_pos tmap);
t_coor	init_coor(void);

//ft_iso.c
t_coor	ft_propiso(t_coor c, t_vars vars);
t_pos	ft_proj_iso(t_coor c, t_vars vars);
t_vars	*ft_rempiso(t_vars *vars);

//ft_vect.c
t_coor	crea_vect(t_coor a, t_coor b);

//ft_point.c
t_coor	crea_p(float tprop, t_coor a);
t_coor	crea_alphap(t_coor A, t_coor a, float t, t_vars *vars);
t_coor	crea_alpha(float zoom);
void	init_local(t_vars *vars);

//ft_coord.c
float	ft_scalaire(t_coor a, t_coor b);
float	ft_prop(t_coor u, t_coor P, t_coor alpha, t_coor alphap);
void	ft_remp(t_vars *vars, t_coor alpha);
void	ft_setup(t_vars *vars);

//fdf_utils
int		ft_atoi(const char *str);
t_pos	ft_count(char *name);
int		ft_subcount(char *str);

//free
void	tabcoor_free(t_coor **tab, t_pos tmap);
void	tabpos_free(t_pos **tab, t_pos tmap);

//print
void	ft_putchar(char c);
void	ft_putstr(char *str);

//newmaptrim
t_coor	*ft_splitcoor(char *s, char c, int l, t_pos tmap);
t_coor	**ft_maptrim(char *name, t_pos tmap, t_vars *vars);


//gnl
size_t	ft_strlen(char *s);
size_t	ft_strchrlen(char *s, char c);
char	*ft_strjoin(char *old, char *src);
char	*ft_strtrim1(char *old);
char	*ft_strtrim2(char *old);
char	*ft_strdup(char *s1);
size_t	ft_strchr(char *s, char c);
char	*get_next_line(int fd, int id, int leak);
int		ft_endfree(char *rst);
int		ft_verifleak(int leak, char *rst);

#endif