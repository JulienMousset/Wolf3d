/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/26 17:26:45 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_mmmap_values(t_map *map, int opt)
{
	map->mm_switch = 1;
	map->mm_size = per(W, 11) * opt; //size of the mmmap
	map->mm_margin = (t_coord) {.x = per(W, 7), .y = per(H, 5)};
	map->mm_vis = 16; // visualization of 40 blocks around
	map->mm_block_size = (W / 64 / 3) * opt;  //size 4 -> 2x2 block
	map->mm_start.x = W - map->mm_margin.x - map->mm_size;
	map->mm_start.y = map->mm_margin.y;
	map->mm_center.x =  W - map->mm_margin.x - map->mm_size / 2;
	map->mm_center.y = map->mm_margin.y + map->mm_size / 2;
	map->mm_end.x = W - map->mm_margin.x;
	map->mm_end.y = map->mm_margin.y + map->mm_size;
}

void	set_values(t_map *map)
{
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->move_coef = 0.1;
	map->rot_coef = 0.08;
	map->run = 0;
	map->menu = 0;
	map->boo = 1;
	map->opt = 1; //minimap size x1 or x2
	map->h2 = H / 2;
	map->var = 0;
	map->boo_spr = 1;
	map->mouse_pos = (t_coord) {.x = W / 2, .y = H / 2};
	place_player(map);
	//map->pos = (t_complex) {.x = 10, .y = 10};
	map->pos.x -= map->dir.x * MOVE_SPEED;
	set_mmmap_values(map, map->opt);
}

void	init_keys(t_map *map)
{
	map->esc = 0;
	map->up = 0;
	map->down = 0;
	map->left = 0;
	map->right = 0;
	map->strafe_left = 0;
	map->strafe_right = 0;
	map->run_mode = 0;
	map->open_map = 0;
	map->respawn = 0;
	map->hide_map = 0;
	map->texture_mode = 0;
	map->map_zoom = 0;
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
	init_keys(env->map);
	set_values(env->map);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W, H, "Wolf3D");
	env->img_ptr = mlx_new_image(env->mlx_ptr, W, H);
	env->data_addr = mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l),
	&(env->endian));
	ft_bzero(env->data_addr, W * H * 4);
	load_textures(env);
	return (1);
}

int		wolf3d(char *file)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, file);
	ray_casting(env, env->map);
	mlx_hook(env->win_ptr, 2, (1L << 0), key_press, env);
	mlx_hook(env->win_ptr, 3, (1L << 1), key_release, env);
	mlx_hook(env->win_ptr, 6, 0, mouse_move, env);
	mlx_hook(env->win_ptr, 17, 0, close_program, env);
	mlx_loop_hook(env->mlx_ptr, multiple_events, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
