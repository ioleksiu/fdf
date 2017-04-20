/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:33:06 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 21:57:28 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define BUFF_SIZE 1000
# include "mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# define W_SIZE  1300

typedef struct		s_xyz
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_xyz;

typedef struct		s_map
{
	t_xyz			**cord;
	void			*mlx;
	void			*win;
	int				x_len;
	int				y_len;
	int				x_count;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
}					t_map;

typedef struct		s_get
{
	char			*rest;
	int				fd;
	struct s_get	*next;
}					t_get;

int					c_count(char *s);
void				map_create(t_map *head, char *av);
void				x_transform(t_map *head, int x_len, int y_len);
void				y_transform(t_map *head, int x_len, int y_len);
void				s_if(int color, t_map *head);
void				s_else(int color, t_map *head);
void				segment(int color, t_map *head);
void				move_up_down(t_map *head, int i);
void				color(t_map *head, int color);
void				div_mult(t_map *head);
void				div_xyz(t_map *head);
void				n_min(t_map *head);
void				n_plus(t_map *head);
int					my_key_funct(int keycode, t_map *head);
void				fill_head_xy(int x, int y, t_map *head);
void				print_xy(t_map *head, int x_len, int y_len);
void				cord_centre(t_map *head, int x_len, int y_len);
void				c_ord(t_map *head, int x_len, int y_len);
void				move_left_right(t_map *head, int i);
void				ft_error(void);
void				valid(char *s, t_map head);
void				fdf(char *s, int x, int y, int fd);

int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
int					ft_countw(const char *s, char sp);
void				ft_bzero(void *s, size_t n);
char				*ft_strncpy(char *dest, const char *sorc, size_t len);
int					ft_counts(const char *s, char sp);
char				*ft_strcat(char *s1, const char *s2);

int					get_next_line(const int fd, char **line);
#endif
