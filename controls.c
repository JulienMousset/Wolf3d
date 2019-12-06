/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:29:42 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/06 18:24:39 by jmousset         ###   ########.fr       */
/*   Updated: 2019/12/06 14:23:12 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	more_keys(int key, t_env *env)
{
	if (key == KEY_M)
		env->map->open_map = env->map->open_map ? 0 : 1;
	if (key == NUM_1)
		env->map->bool_tex = env->map->bool_tex ? 0 : 1;
	if (key == TAB && env->map->item_map)
	{
		env->map->opt = env->map->opt == 1 ? 2 : 1;
		set_mmap_values(env->map, env->map->opt);
	}
	if (key == NUM_3)
		env->map->bool_spr = env->map->bool_spr ? 0 : 1;
	if (key == NUM_4)
		env->map->mm_color = env->map->mm_color ? 0 : 1;
	if (key == NUM_5)
		env->map->pick_coin++;
	if (key == NUM_6)
		env->map->pick_key++;
	if (key == NUM_7)
		env->map->pick_heart--;
	if (key == NUM_8)
		env->map->pick_heart++;
	if (key == ARROW_UP)
		env->map->look_up = 1;
	if (key == ARROW_DOWN)
		env->map->look_down = 1;
	if (env->map->pick_heart < 1)
		env->map->pick_heart = 1;
	if (env->map->pick_heart > env->map->container * 2)
		env->map->pick_heart = env->map->container * 2;
}

int		key_press(int key, t_env *env)
{
	if (key == KEY_ESC)
		close_program(env);
	if (key == KEY_W)
		env->map->up = 1;
	if (key == KEY_S)
		env->map->down = 1;
	if (key == KEY_A)
		env->map->left = 1;
	if (key == KEY_D)
		env->map->right = 1;
	if (key == KEY_Q)
		env->map->strafe_left = 1;
	if (key == KEY_E)
		env->map->strafe_right = 1;
	if (key == KEY_SHIFT && env->map->item_heels)
		env->map->run = 1;
	if (key == KEY_SPACE)
	{
		set_values(env->map);
		copy_board(env->map);
		create_sprites_array(env->map);
	}
	more_keys(key, env);
	return (0);
}

int		key_release(int key, t_env *env)
{
	if (key == KEY_W)
		env->map->up = 0;
	if (key == KEY_S)
		env->map->down = 0;
	if (key == KEY_A)
		env->map->left = 0;
	if (key == KEY_D)
		env->map->right = 0;
	if (key == KEY_Q)
		env->map->strafe_left = 0;
	if (key == KEY_E)
		env->map->strafe_right = 0;
	if (key == KEY_SHIFT)
		env->map->run = 0;
	if (key == ARROW_UP)
		env->map->look_up = 0;
	if (key == ARROW_DOWN)
		env->map->look_down = 0;
	return (0);
}

int		multiple_events(t_env *env)
{
	if (env->map->up == 1 || env->map->down == 1)
		up_or_down(env->map, env->map->board, env->map->dir);
	if (env->map->left == 1 || env->map->right == 1)
	{
		env->map->mouse_left = 0;
		env->map->mouse_right = 0;
		left_or_right(env->map, env->map->rot_coef);
	}
	if (env->map->strafe_left == 1 || env->map->strafe_right == 1)
		strafe(env->map, env->map->board, env->map->dir);
	if (env->map->open_map == 1)
		env->map->bool_menu = 1;
	else if (env->map->open_map == 0)
		env->map->bool_menu = 0;
	if (env->map->look_up == 1 || env->map->look_down == 1)
		look_up_down(env->map);
	if (env->map->mouse_left == 1 || env->map->mouse_right == 1)
		left_or_right(env->map, env->map->rot_coef / 1);
	if (env->map->camera_h == 5)
	{
		env->map->look_up = 0;
		env->map->look_down = 0;
		env->map->camera_h = 0;
	}
	env->map->camera_h++;
	if (env->map->camera_w == 5)
	{
		env->map->mouse_left = 0;
		env->map->mouse_right = 0;
		env->map->camera_w = 0;
	}
	env->map->camera_w++;
	image_to_window(env, env->map);
	return (0);
}
