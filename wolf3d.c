/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/01 22:03:18 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_mmmap_values(t_map *map)
{
	map->mm_switch = 1;
	map->mm_size = per(W, 10); //size of the mmmap
	map->mm_vis = 32; // visualization of 40 blocks around
	map->mm_block_size = 4;  //size 4 -> 2x2 block
	map->mm_start.x = map->pos.x - map->mm_vis / 2;
	map->mm_start.y = map->pos.y - map->mm_vis / 2;
	map->mm_end.x = map->pos.x + map->mm_vis / 2;
	map->mm_end.y = map->pos.y + map->mm_vis / 2;
}

void	set_values(t_map *map)
{
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->move_coef = 0.1;
	map->rot_coef = 0.08;
	map->run = 0;
	map->menu = 0;
	map->mouse_pos = (t_coord) {.x = W / 2, .y = H / 2};
	place_player(map);
	set_mmmap_values(map);
}

int		init_structure(t_env *env, char *file)
{
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(parsing(env->map, file)))
		free_and_display_usage(env);
	set_values(env->map);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W, H, "Wolf3D");
	env->img_ptr = mlx_new_image(env->mlx_ptr, W, H);
	env->data_addr = mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l),
	&(env->endian));
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
	mlx_hook(env->win_ptr, 6, 0, mouse_move, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
