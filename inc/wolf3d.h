/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:04:33 by jmousset          #+#    #+#             */
/*   Updated: 2020/07/09 15:14:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "colors.h"
# include "controls.h"
# include "sprites.h"

# define W 1280
# define H 960
# define W_SKY 1920
# define H_SKY 1080
# define TS 64
# define THREADS 4

# define MOVE_SPEED 0.15
# define ROT_SPEED 0.08
# define SCALE_MS 5

# define NUM_TEX 64

# define ERR_USAGE "Usage: ./wolf3d <filename>"
# define ERR_MALLOC "Error trying to allocate memory."
# define ERR_DIR "You're trying to read a directory or a wrong type of file."
# define ERR_WRONG "Wrong input. Your map can only contain digits and letters."
# define ERR_BORDER "The borders of your map can't be an empty space."
# define ERR_NO_PLAYER "No player placed on your map."
# define ERR_PLAYER "More than one player placed on your map."
# define ERR_LINE "Your map needs the same number of lines for each column."

# define POOR "NOT ENOUGH COINS"
# define FULL_HEALTH "FULL HEALTH"
# define PRESS "PRESS [G] TO GAMBLE"

# define CON_0 "[H]ELP"
# define CON "CONTROLS"
# define CON_1 "Move : [WASD] or [ARROW KEYS]"
# define CON_2 "Strafe : [Q][E]"
# define CON_3 "Look Up/Down : [<][>]"
# define CON_4 "Reset Run : [SPACEBAR]"
# define CON_5 "Run : [SHIFT]"
# define CON_6 "Open Map : [TAB]"
# define CON_7 "Gamble : [G]"
# define CON_8 "Quit : [ESC]"
# define CON_9 "Cardinal Mode : [C]"
# define CON_10 "Texture Mode : [1]"
# define CON_11 "Skybox Mode : [2]"
# define CON_12 "Sprites Mode : [3]"
# define CON_13 "Dark Mode : [4]"
# define CON_14 "Gain Coins/Keys : [5][6]"
# define CON_15 "Loose/Gain Hearts : [7][8]"
# define CON_16 "Admin Mode : [9]"

# define QUOTE1_1 "Did you know that the end of the game"
# define QUOTE1_2 "is actually 4 tiles behind my back?"
# define QUOTE2_1 "I miss my owner."
# define QUOTE2_2 "He still has my left paw."
# define QUOTE3_1 "The first known account of execution by hanging"
# define QUOTE3_2 "was in Homer's Odyssey (Book XXII)."
# define QUOTE4_1 "ITEMS - 15 COINS"
# define QUOTE4_2 "CONSUMABLES - 5 COINS"

# define WIN "Dear Diary, today I WON."
# define LOSE "Dear Diary, today I DIED."
# define END1 "Press [ESC] to EXIT."
# define END2 "Press [SPACE] to RESTART."

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_complex
{
	double			x;
	double			y;
}					t_complex;

typedef struct		s_img
{
	void			*img_ptr;
	char			*data_addr;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_spr
{
	double			x;
	double			y;
	int				width;
	int				height;
}					t_spr;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				i;
}					t_sprite;

typedef struct		s_map
{
	int				**board;
	int				**board_cpy;
	char			**tmp;
	char			*line;
	int				nb_lines;
	int				nb_columns;
	int				h2;
	int				h2_coef;
	int				min;
	int				max;
	char			*level;
	int				walk;
	t_complex		pos;
	t_complex		pos_cpy;
	t_complex		dir;
	t_complex		plane;
	double			move_coef;
	double			rot_coef;
	double			run;
	int				y_start;
	int				y_end;
	int				id;
	int				i;
	int				r;
	int				color;
	double			z_buffer[W];
	t_sprite		*s;
	int				*spr_order;
	double			*spr_dist;
	t_spr			spr;
	double			inv_det;
	t_complex		transform;
	int				ssx;
	int				x_start;
	int				x_end;
	char			*color_str;
	int				nb_sprites;
	int				pick_coin;
	int				pick_heart;
	int				container;
	int				pick_key;
	t_coord			prev_id;
	int				item_map;
	int				item_heels;
	int				item_poly;
	int				item_ipecac;
	int				item_godhead;
	int				item_candle;
	int				item_quarter;
	int				item_axe;
	int				item_mantle;
	int				item_xray;
	int				item_dinner;
	int				item_counter;
	int				final_score;
	t_coord			mouse_pos;
	int				opt;
	t_coord			mm_start;
	t_coord			mm_center;
	t_coord			mm_end;
	int				mm_size;
	int				mm_vis;
	int				mm_block_size;
	t_coord			mm_margin;
	int				mm_color;
	t_coord			gui_margin;
	int				gui_scale;
	int				gui_size;
	int				gui_counter;
	char			*gui_str;
	int				bool_tex;
	int				bool_spr;
	int				bool_menu;
	int				bool_ceil;
	int				bool_card;
	int				bool_smog;
	int				bool_dead;
	int				bool_win;
	int				up;
	int				down;
	int				left;
	int				right;
	int				strafe_left;
	int				strafe_right;
	int				run_mode;
	int				look_up;
	int				look_down;
	int				mouse_left;
	int				mouse_right;
	int				camera_w;
	int				camera_h;
	t_coord			prev;
}					t_map;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_addr;
	int				bpp;
	int				s_l;
	int				endian;
	t_map			*map;
	t_img			t[NUM_TEX];
	char			*path[NUM_TEX];
	t_img			sky;
}					t_env;

typedef struct		s_thread
{
	pthread_t		t;
	int				n;
	t_env			*env;
	double			camera_x;
	t_complex		ray_dir;
	t_coord			block;
	t_complex		side;
	t_complex		delta;
	double			perp;
	t_coord			step;
	int				hit;
	int				ns_or_ew;
	int				line_height;
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
	int				color;
	int				dif;
	double			wall_x;
	t_coord			tex;
	int				d;
	int				j;
	int				id;
	t_complex		floor;
	double			dist_wall;
	double			dist_player;
	double			dist_current;
	t_complex		current_floor;
	t_complex		floor_tex;
	char			*color_str;
}					t_thread;

int					wolf3d(char *file);
int					init_structure(t_env *env, char *file);
void				free_and_display_usage(t_env *env, char *s);

int					parsing(t_env *env, char *file);
int					check_file(t_env *env, char *file);
int					check_map(char *s);
int					count_lines(t_map *map, char *file);
int					count_colums(t_map *map, char *file);

int					fill_board(t_env *env, int fd);
void				filling(t_map *map, int i, int *j, int *player);
int					is_valid(char *s, int i);
int					is_upper(int i);
int					check_board(t_map *map);

void				set_keys(t_map *map);
void				set_values(t_map *map);
void				set_values2(t_map *map);
void				set_mmap_values(t_map *map, int opt);

void				load_textures(t_env *env, t_img *t, char **path);
void				load_paths(char **path);
void				load_paths2(char **path);
void				load_paths3(char **path);

void				create_sprites_array(t_map *map);
int					nb_sprites(t_map *map);
t_sprite			add_sprite(double x, double y, int i);
void				alloc_arrays(t_map *map);
void				realloc_array(t_map *map, int x, int y, int id);

void				gain_item(t_map *map, int id);
void				pickup_chance(t_map *map, int id);
void				buy_item(t_map *map, int id);
void				buy_item_99(t_map *map, int id);
void				set_limits(t_map *map, int id);

int					is_walkable(t_map *map, int id, int x, int y);
void				curse_door(t_map *map, int id);
void				trade(t_map *map, int **board);
void				interact_solid(t_map *map, int id);
int					in_array(t_map *map, int x, int y);

int					is_destroyable(t_map *map, int id);
int					is_door(t_map *map, int id, int x, int y);
int					is_shop(t_map *map, int id, int coin);
int					is_walk(t_map *map, int id);
int					is_pickable(t_map *map, int id);

void				image_to_window(t_env *env, t_map *map);
void				*ray_casting(void *vt);
void				set_dda_values(t_thread *t, t_map *map);
void				dda(t_thread *t, t_map *map);
void				set_walls(t_thread *t, t_map *map, int x_start);

void				create_threads(t_env *env, int id);
void				free_threads(t_thread *t);

void				draw_line(t_env *env, t_thread *t, int x, int y_start);
void				pick_color(t_env *env, t_thread *t, int x, int y_start);
void				print_cardinal_walls(t_env *env, t_thread *th, int j);
int					choose_color(t_map *map, int id, int ns_or_ew);
void				put_pixel(t_env *env, int x, int y, int color);

void				floor_casting(t_env *env, t_map *map, t_thread *t, int x);
void				set_floor_casting(t_thread *t, int *y);
int					level_id(t_map *map, int id);
void				ceiling_casting(t_env *env, t_thread *t, int x, int y);

void				sprites(t_env *env, t_map *map);
void				set_sprite_values(t_map *map, int i);
void				*horizontal_loop(void *vt);
void				vertical_loop(t_thread *t, t_env *env, t_map *map);

void				draw_sky(t_env *env, t_map *map);
void				draw_responsive_sky(t_env *env, t_map *map);
void				draw_simple_sky(t_env *env, t_map *map);

void				draw_minimap(t_env *env, t_map *map);
void				draw_mini_background(t_env *env, t_map *map);
void				put_n_pixel(t_env *env, int xx, int yy, int id);
int					mm_color(t_map *map, int id, int i);

int					north(t_map *map, int x);
int					south(t_map *map, int x);
int					west(t_map *map, int y);
int					east(t_map *map, int y);

void				gui(t_env *env, t_map *map, int **board);
void				print_hearts(t_env *env, t_map *map);
void				print_items_gui(t_env *env, t_map *map, int n);
void				print_mini_sprite(t_env *env, t_map *map, int id,
t_coord margin);
int					is_large_sprite(int id);

void				menu(t_env *env);
void				menu_text(t_env *env, int pw, int ph);

void				text_gui(t_env *env, t_map *map, int **board);
void				print_shop_message(t_env *env, t_map *map, int **board);
void				sprite_interactions(t_env *env, int id);
void				get_quote(t_env *env, int id);

void				end_game(t_env *env, t_map *map);
int					final_score(t_map *map);
void				won_or_lost(t_env *env, t_map *map);

int					multiple_events(t_env *env);
int					key_press(int key, t_env *env);
void				key_press2(int key, t_env *env);
void				key_press3(int key, t_env *env);
int					key_release(int key, t_env *env);
int					mouse_move(int x, int y, t_env *env);

int					close_program(t_env *env);
void				up_or_down(t_map *map, int **board, t_complex dir);
void				left_or_right(t_map *map, double rot_coef);
void				strafe(t_map *map, int **board, t_complex dir);
void				look_up_down(t_map *map);

void				display_result(t_env *env, t_map *map);
int					*ft_strint(int size);
void				display_values(t_map *map);
void				set_mmap_values(t_map *map, int opt);

void				reset_game(t_map *map);
int					*array_cpy(int *src, int size);
void				admin_mode(t_map *map);
int					randomy(int min, int max);
t_coord				size(t_map *map, int id, int n);
void				stop_camera(t_env *env);
unsigned int		darken(t_env *env, unsigned int c, double d, int candle);
void				bubble_sort(int	*order, double *dist, int amount);
int					**board_cpy(int **src, int nb_lines, int nb_columns);
void				draw_background(t_env *env);

#endif
