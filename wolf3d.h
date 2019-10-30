/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:37:26 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/30 21:19:48 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/10/29 14:40:31 by jmousset         ###   ########.fr       */
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

# define W 800
# define H 600

# define WIDTH 640
# define HEIGHT 480
# define THREADS 8

# define ERR_MALLOC "error trying to allocate memory"
# define ERR_USAGE "Usage: ./wolf3d <filename>"
# define ERR_DIR "Input is a directory"
# define ERR_WRONG "Wrong input file"
# define ERR_LENGTH "Found wrong line length. Exiting."
# define ERR_EMPTY "No data found."
# define ERR_NOFILE "File doesn't exit."
# define ERR_FULL "Map without place for the player."

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_map
{
	int			**board;
	char		**tmp;
	char		*line;
	int			nb_lines;
	int			nb_columns;

	t_complex	pos;
	t_complex	dir;
	t_complex	plane;
	double		cameraX;
	t_complex	rayDir;
	t_complex	time;

	t_coord		block;
	t_complex	side;
	t_complex	delta;
	double		perp;
	t_coord		step;
	int			hit;
	int			boo;

	int			wallHeight;
	t_coord		minMax;
	int			color;

}				t_map;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
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
int				free_board(t_map *map);
int				wolf3d(char *file);
int				init_structure(t_env *env, char *file);
int				parsing(t_map *map, char *file);
int				check_file(t_map *map, char *file);
int				check_map(char *s);
int				count_lines(t_map *map, char *file);
int				count_colums(t_map *map, char *file);
int				fill_board(t_map *map, int fd);
int				check_board(t_map *map);
int				close_program(t_env *env);

int				key_press(int key, void *param);

double			abso(double a);
void			ray_casting(t_env *env, t_map *map);

void			menu(t_env *env);

void			choose_color(t_map *map, int ip, int boo);
void			draw_line(t_env *env, int i, t_coord minMax, int color);
void			put_pixel(t_env *env, int x, int y, int color);
void			draw_background(t_env *env);




#endif
