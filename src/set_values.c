/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:29:58 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/13 19:06:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	set_mmap_values(t_map *map, int opt)
{
	map->mm_size = per(W, 11) * opt;
	map->mm_margin = (t_coord) {.x = per(W, 7), .y = per(H, 5)};
	map->mm_vis = 12 * opt;
	map->mm_block_size = (W / 64 / 3);
	map->mm_start.x = W - map->mm_margin.x - map->mm_size;
	map->mm_start.y = map->mm_margin.y;
	map->mm_center.x = W - map->mm_margin.x - map->mm_size / 2;
	map->mm_center.y = map->mm_margin.y + map->mm_size / 2;
	map->mm_end.x = W - map->mm_margin.x;
	map->mm_end.y = map->mm_margin.y + map->mm_size;
	map->mm_color = 1;
}

void	set_values2(t_map *map)
{
	map->run = 0;
	map->opt = 1;
	map->item_map = 1;
	map->item_heels = 1;
	map->item_poly = 0;
	map->item_ipecac = 0;
	map->item_godhead = 0;
	map->item_candle = 10;
	map->item_quarter = 0;
	map->item_axe = 0;
	map->item_mantle = 0;
	map->item_xray = 0;
	map->item_dinner = 0;
	map->item_counter = 0;
	map->final_score = 0;
	map->s = NULL;
	map->spr_order = NULL;
	map->spr_dist = NULL;
	map->gui_scale = 2;
	map->gui_counter = 2;
	map->gui_size = TS * map->gui_scale;
	map->gui_margin = (t_coord) {.x = -TS / 2, .y = -TS * 1.5};
	map->mouse_pos = (t_coord) {.x = W / 1, .y = H / 1};
}

void	set_values(t_map *map)
{
	map->pos = map->pos_cpy;
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->move_coef = MOVE_SPEED;
	map->rot_coef = ROT_SPEED;
	map->h2 = H / 2;
	map->h2_coef = 25;
	map->min = per(H, 20);
	map->max = per(H, 80);
	map->walk = 0;
	map->nb_sprites = 0;
	map->bool_tex = 1;
	map->bool_ceil = 1;
	map->bool_spr = 1;
	map->bool_smog = 0;
	map->bool_menu = 0;
	map->bool_card = 0;
	map->bool_dead = 0;
	map->bool_win = 0;
	map->container = 3;
	map->pick_heart = 6;
	map->pick_coin = 15;
	map->pick_key = 15;
	set_values2(map);
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
	map->look_up = 0;
	map->look_down = 0;
	map->mouse_left = 0;
	map->mouse_right = 0;
	map->camera_w = 0;
	map->camera_h = 0;
	map->prev = (t_coord) {.x = 0, .y = 0};
}
