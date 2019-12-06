/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:23:00 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/06 18:32:22 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/12/06 18:11:42 by jmousset         ###   ########.fr       */
/*   Updated: 2019/12/06 17:28:46 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/12/06 14:05:47 by jmousset         ###   ########.fr       */
/*   Updated: 2019/11/27 19:34:28 by jmousset         ###   ########.fr       */
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
# include "sprites.h"

# define W 1280
# define H 960
# define TS 64
# define THREADS 4

# define MOVE_SPEED 0.125
# define ROT_SPEED 0.08
# define SCALE_MS 2

#define NUM_TEX	59

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
	int			**board_cpy;
	char		**tmp;
	char		*line;
	int			nb_lines;
	int			nb_columns;
	int			h2;

	int			walk;

	t_complex	pos;
	t_complex	pos_cpy;
	t_complex	old_dir;
	t_complex	dir;
	t_complex	old_plane;
	t_complex	plane;

	double		move_coef;
	double		rot_coef;

	double		run;

	int			y_start;
	int			y_end;
	t_coord		tex;
	int			id;
	int			d;
	int			i;
	int			color;

	double		z_buffer[W];
	t_sprite	*s;
	int			*spr_order;
	double		*spr_dist;
	t_spr		spr;
	double		inv_det;
	t_complex	transform;
	int			ssx;
	int			x_start;
	int			x_end;
	char		*color_str;
	int			nb_sprites;

	int			pick_coin;
	int			pick_heart;
	int			container;
	int			pick_key;

	t_coord		prev_id;
	int			item_map;
	int			item_heels;
	int			item_poly;
	int			item_ipecac;
	int			item_godhead;
	int			item_candle;

	t_coord		mouse_pos;

	int			opt;
	t_coord		mm_start;
	t_coord		mm_center;
	t_coord		mm_end;
	int			mm_size;
	int			mm_vis;
	int			mm_block_size;
	t_coord		mm_margin;
	int			mm_color;

	t_coord		gui_margin;
	int			gui_scale;
	int			gui_size;
	int			gui_counter;
	char		*gui_str;

	int			bool_tex;
	int			bool_spr;
	int			bool_menu;
	int			bool_print_price;

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
	int			look_up;
	int			look_down;
	int			mouse_left;
	int			mouse_right;
	int			old_x;
	double		old_dir_x;

	int			camera_w;
	int			camera_h;

	t_coord		prev;
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
	char		*path[NUM_TEX];
	t_img		sky;
}				t_env;

typedef struct	s_thread
{
	pthread_t	t;
	int			n;
	t_env		*env;


	double		camera_x;
	t_complex	ray_dir;

	t_coord		block;
	t_complex	side;
	t_complex	delta;

	double		perp;
	t_coord		step;
	int			hit;
	int			ns_or_ew;

	int			line_height;
	int			x_start;
	int			x_end;
	int			y_start;
	int			y_end;
	int			color;
	int			dif;

	double		wall_x;
	t_coord		tex;
	int			d;
	int			j;
	int			id;

	t_complex	floor;
	double		dist_wall;
	double		dist_player;
	double		dist_current;
	t_complex	current_floor;
	t_complex	floor_tex;
	char		*color_str;

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

void			set_dda_values(t_thread *t, t_map *map);
void			dda(t_thread *t, t_map *map);
void			set_walls(t_thread *t, t_map *map);
void			display_result(t_env *env, t_map *map);

int				choose_color(int id, int ns_or_ew);
void			draw_line(t_env *env, t_thread *t, int x, int y_start);
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

void			text_gui(t_env *env);
void			gui(t_env *env, t_map *map);
void			menu(t_env *env);
void			set_mmap_values(t_map *map, int opt);

void			draw_minimap(t_env *env, t_map *map);

void			load_textures(t_env *env, t_img *t, char **path);
void			pick_color(t_env *env, t_thread *t, int x, int y_start);

void			draw_sky(t_env *env, t_map *map);
void			look_up_down(t_map *map);

int				mouse_move(int x, int y, t_env *env);
int				multiple_events(t_env *env);
void			look_left_right(t_map *map);

unsigned int	add_smog(unsigned int c, double d, int candle);

void			sprites(t_env *env, t_map *map);
void			bubble_sort(int	*order, double *dist, int amount);

int				is_walkable(t_map *map, int i, int x, int y);

void			realloc_array(t_map *map, int x, int y, int id);
int				in_array(t_map *map, int x, int y);

void			print_mini_sprite(t_env *env, t_map *map, int id, t_coord margin);

void			create_sprites_array(t_map *map);
int				**ft_tabcpy(int **src, int nb_lines, int nb_columns);
void			ft_tabdel(int **tab, int lines);
void			copy_board(t_map *map);

int				close_program(t_env *env);
void			set_ceil_casting(t_map *map);
void			floor_casting(t_env *env, t_map *map, t_thread *t,  int x);
void			ceil_casting(t_env *env, t_map *map, int x);



void			create_threads(t_env *env, int id);
void			print_mini_sprite(t_env *env, t_map *map, int id, t_coord margin);


int				north(t_map *map, int x);
int				south(t_map *map, int x);
int				west(t_map *map, int y);
int				east(t_map *map, int y);

void			*ray_casting(void *vt);

int				ft_ishupper(int i);

void			image_to_window(t_env *env, t_map *map);

void			*horizontal_loop(void *vt);

#endif

