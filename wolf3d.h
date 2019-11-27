/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:23:00 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/27 15:12:58 by jmousset         ###   ########.fr       */
/*   Updated: 2019/11/27 12:47:03 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/11/15 10:03:20 by jmousset         ###   ########.fr       */
/*   Updated: 2019/11/13 21:53:20 by pasosa-s         ###   ########.fr       */
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
# include "colors.h"
# include "controls.h"

# define W 1280
# define H 960
# define TS 64
# define THREADS 8
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.08

#define NUM_TEX	10
# define NUM_SPR 3

# define ERR_MALLOC "error trying to allocate memory"
# define ERR_USAGE "Usage: ./wolf3d <filename>"
# define ERR_DIR "Input is a directory"
# define ERR_WRONG "Wrong input file"
# define ERR_LENGTH "Found wrong line length. Exiting."
# define ERR_EMPTY "No data found."
# define ERR_NOFILE "File doesn't exit."
# define ERR_FULL "Map without place for the player."

# define BARREL "textures/barrel.XPM"
# define BLUESTONE "textures/bluestone.XPM"
# define COLORSTONE "textures/colorstone.XPM"
# define EAGLE "textures/eagle.XPM"
# define GREENLIGHT "textures/greenlight.XPM"
# define GREYSTONE "textures/greystone.XPM"
# define MOSSY "textures/mossy.XPM"
# define PILLAR "textures/pillar.XPM"
# define PSTONE "textures/purplestone.XPM"
# define REDBRICK "textures/redbrick.XPM"
# define WOOD "textures/wood.XPM"

# define SKYBOX "textures/pixel_sky.XPM"

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


typedef struct	s_card
{
	char	*str;
	int		x;
	int		y;
}				t_card;

typedef struct	s_cards
{
	t_card	e;
	t_card	w;
	t_card	n;
	t_card	s;

}				t_cards;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data_addr;
	int			bpp;
	int			s_l;
	int			endian;
}				t_img;

typedef struct	s_spr
{
	double		x;
	double		y;
	int			width;
	int			height;
}				t_spr;

typedef struct	s_sprite
{
	double	x;
	double	y;
	int		i;
}				t_sprite;

typedef struct	s_map
{
	int			**board;
	char		**tmp;
	char		*line;
	int			nb_lines;
	int			nb_columns;
	int			h2;

	t_complex	pos;
	t_complex	old_dir;
	t_complex	dir;
	t_complex	old_plane;
	t_complex	plane;
	double		camera_x;
	t_complex	ray_dir;

	double		move_coef;
	double		rot_coef;

	double		run;
	int			menu;

	t_coord		block;
	t_complex	side;
	t_complex	delta;
	double		perp;
	t_coord		step;
	int			hit;
	int			ns_or_ew;

	int			line_height;
	int			y_start;
	int			y_end;
	int			color;

	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			d;
	int			id;
	int			boo;

	double		z_buffer[W];
	t_sprite	s[NUM_SPR];
	int			spr_order[NUM_SPR];
	double		spr_dist[NUM_SPR];
	t_spr		spr;
	double		inv_det;
	t_complex	transform;
	int			ssx;
	int			x_start;
	int			x_end;
	int			boo_spr;
	int			boo_print;
	char		*color_str;

	t_coord		mouse_pos;

	int			opt;
	int			mm_switch;
	t_coord		mm_start;
	t_coord		mm_center;
	t_coord		mm_end;
	int			mm_size;
	int			mm_vis;
	int			mm_block_size;
	t_coord		mm_margin;

	int			esc;
	int			up;
	int			down;
	int			left;
	int			right;
	int			strafe_left;
	int			strafe_right;
	int			run_mode;
	int			open_map;
	int			respawn;
	int			hide_map;
	int			texture_mode;
	int			map_zoom;
	int			look_up;
	int			look_down;
	int			mouse_left;
	int			mouse_right;
	int			old_x;
	double		old_dir_x;

	int			camera_w;
	int			camera_h;

	t_coord		prev;

	t_complex	floor;
	double		dist_wall;
	double		dist_player;
	double		dist_current;
	t_complex	current_floor;
	t_complex	floor_tex;
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
	t_img		t[NUM_TEX];
	t_img		sky;
}				t_env;

typedef struct	s_thread
{
	pthread_t	t;
	int			n;
	t_env		*env;
}				t_thread;

void			free_and_display_usage(t_env *env);
void			free_tmp_board(char **s);
int				free_board(t_map *map);

int				wolf3d(char *file);
int				init_structure(t_env *env, char *file);
void			set_values(t_map *map);

int				parsing(t_map *map, char *file);
int				check_file(t_map *map, char *file);
int				check_map(char *s);
int				count_lines(t_map *map, char *file);
int				count_colums(t_map *map, char *file);

int				check_board(t_map *map);
int				fill_board(t_map *map, int fd);

void			ray_casting(t_env *env, t_map *map);
void			set_dda_values(t_map *map);
void			dda(t_map *map);
void			set_walls(t_map *map);
void			display_result(t_env *env, t_map *map);

int				choose_color(int id, int ns_or_ew);
void			draw_line(t_env *env, t_map *map, int x, int y_start);
void			put_pixel(t_env *env, int x, int y, int color);

int				key_press(int key, t_env *env);
int				key_release(int key, t_env *env);
int				close_program(t_env *env);
void			up_or_down(t_map *map, int **board, t_complex dir);
void			left_or_right(t_map *map, double rot_coef);
void			strafe(t_map *map, int **board, t_complex dir);

void			draw_background(t_env *env);
int				*ft_strint(int size);
void			display_values(t_map *map);

void			text_menu(t_env *env);
void			menu(t_env *env);
void			set_mmmap_values(t_map *map, int opt);

unsigned long	get_time(void);
int				place_player(t_map *map);
void			draw_minimap(t_env *env, t_map *map);

void			load_textures(t_env *env);
void			pick_color(t_env *env, t_map *map, int x, int y_start);

void			draw_sky(t_env *env, t_map *map);
void			look_up_down(t_map *map);

int				mouse_move(int x, int y, t_env *env);
double			convert(int old, double min, double max, int length);
int				multiple_events(t_env *env);
void			look_left_right(t_map *map);

unsigned int	add_smog(unsigned int c, double d);

void			sprites(t_env *env, t_map *map);
void			bubble_sort(int	*order, double *dist, int amount);

#endif

