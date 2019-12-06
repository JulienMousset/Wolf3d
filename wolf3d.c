/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:57:07 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/06 18:24:37 by jmousset         ###   ########.fr       */
/*   Updated: 2019/12/06 14:50:37 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_mmap_values(t_map *map, int opt)
{
	map->mm_size = per(W, 11) * opt; //size of the mmmap
	map->mm_margin = (t_coord) {.x = per(W, 7), .y = per(H, 5)};
	map->mm_vis = 12 * opt; // visualization of 40 blocks around
	map->mm_block_size = (W / 64 / 3);  //size 4 -> 2x2 block
	map->mm_start.x = W - map->mm_margin.x - map->mm_size;
	map->mm_start.y = map->mm_margin.y;
	map->mm_center.x =  W - map->mm_margin.x - map->mm_size / 2;
	map->mm_center.y = map->mm_margin.y + map->mm_size / 2;
	map->mm_end.x = W - map->mm_margin.x;
	map->mm_end.y = map->mm_margin.y + map->mm_size;
	map->mm_color = 0;
}

void	set_values(t_map *map)
{
	map->pos = map->pos_cpy;
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->move_coef = MOVE_SPEED;
	map->rot_coef = ROT_SPEED;
	map->run = 0;
	map->opt = 1; //minimap size x1 or x2
	map->h2 = H / 2;

	map->walk = 0;

	map->nb_sprites = 0;
	map->bool_tex = 1;
	map->bool_spr = 1;
	map->bool_menu = 0;
	map->bool_print_price = 0;
	map->container = 3;
	map->pick_heart = 6;
	map->pick_coin = 0;
	map->pick_key = 0;
	map->item_map = 1;
	map->item_heels = 1;
	map->item_poly = 0;
	map->item_ipecac = 0;
	map->item_godhead = 0;
	map->s = NULL;
	map->spr_order = NULL;
	map->spr_dist = NULL;
	map->gui_scale = 2;
	map->gui_counter = 2;
	map->gui_size = TS * map->gui_scale;
	map->gui_margin = (t_coord) {.x = - TS / 2, .y = - TS * 1.5};
	map->mouse_pos = (t_coord) {.x = W / 1, .y = H / 1};
	map->pos.x -= map->dir.x * MOVE_SPEED;
	set_mmap_values(map, map->opt);
}

void	set_keys(t_map *map)
{
	map->up = 0;
	map->down = 0;
	map->left = 0;
	map->right = 0;
	map->strafe_left = 0;
	map->strafe_right = 0;
	map->run_mode = 0;
	map->open_map = 0;
	map->look_up = 0;
	map->look_down = 0;
	map->mouse_left = 0;
	map->mouse_right = 0;
	map->camera_w = 0;
	map->camera_h = 0;
	map->prev = (t_coord) {.x = 0, .y = 0};
}

int		init_structure(t_env *env, char *file)
{
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(parsing(env->map, file)))
		free_and_display_usage(env);
	set_keys(env->map);
	set_values(env->map);
	env->map->board_cpy = ft_tabcpy(env->map->board, env->map->nb_lines,
			env->map->nb_columns);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W, H, "Wolf3D");
	env->img_ptr = mlx_new_image(env->mlx_ptr, W, H);
	env->data_addr = mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l),
	&(env->endian));
	ft_bzero(env->data_addr, W * H * 4);
	load_textures(env, env->t, env->path);
	return (1);
}

int		wolf3d(char *file)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, file);
	image_to_window(env, env->map);
	mlx_hook(env->win_ptr, 2, (1L << 0), key_press, env);
	mlx_hook(env->win_ptr, 3, (1L << 1), key_release, env);
	mlx_hook(env->win_ptr, 6, 0, mouse_move, env);
	mlx_hook(env->win_ptr, 17, 0, close_program, env);
	mlx_loop_hook(env->mlx_ptr, multiple_events, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
