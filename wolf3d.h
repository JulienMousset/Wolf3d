/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:37:26 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/23 18:50:58 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define THREADS 8

typedef struct	s_map
{
	int			**board;
	char		**tmp;
	char		*line;
	int			nb_lines;
	int			nb_columns;
}				t_map;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data_ptr;
	int			bpp;
	int			s_l;
	int			endian;
	t_map		*map;
}				t_env;

typedef struct	s_thread
{
	pthread_t	t;
	int			n;
	t_env		*env;
}				t_thread;

void			display_usage(void);
void			free_and_display_usage(t_env *env);
void			free_tmp_board(char **s);

int				wolf3d(char *file);

int				parsing(t_map *map, char *file);
int				check_file(t_map *map, char *file);
int				check_map(char *s);
int				count_lines(t_map *map, char *file);
int				count_colums(t_map *map, char *file);
int				fill_board(t_map *map, int fd);
int				check_board(t_map *map, int **board);

#endif
