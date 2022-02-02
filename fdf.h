/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjallet <fjallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:50:29 by fjallet           #+#    #+#             */
/*   Updated: 2022/02/02 17:41:29 by fjallet          ###   ########.fr       */
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

typedef struct s_list	t_list;

struct s_list
{
	int		content;
	t_list	*next;
};

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