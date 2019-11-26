/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:02:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/25 18:44:20 by jmousset         ###   ########.fr       */
/*   Updated: 2019/10/31 18:15:06 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	left_or_right(t_map *map, double rot_coef)
{
	double	old_dir;
	double	old_plane;
	double	rot_speed;

	old_dir = map->dir.x;
	old_plane = map->plane.x;
	if (map->right == 1 || map->mouse_right == 1)
		rot_speed = rot_coef * -M_PI / 2;
	else
		rot_speed = rot_coef * M_PI / 2;
	map->dir.x = map->dir.x * cos(rot_speed) - map->dir.y * sin(rot_speed);
	map->dir.y = old_dir * sin(rot_speed) + map->dir.y * cos(rot_speed);
	map->plane.x = map->plane.x * cos(rot_speed) - map->plane.y * sin(rot_speed);
	map->plane.y = old_plane * sin(rot_speed) + map->plane.y * cos(rot_speed);
}

void	up_or_down(t_map *map, int **board, t_complex dir)
{
	double	move_speed;

	move_speed = (map->run == 1) ? map->move_coef * 2 : map->move_coef;
	if (map->up == 1)
	{
		map->pos.x = (board[(int)(map->pos.x + dir.x)][(int)map->pos.y] == 0) ?
			map->pos.x += dir.x * move_speed : map->pos.x;
		map->pos.y = (board[(int)map->pos.x][(int)(map->pos.y + dir.y)] == 0) ?
			map->pos.y += dir.y * move_speed : map->pos.y;
	}
	if (map->down == 1)
	{
		map->pos.x = (board[(int)(map->pos.x - dir.x)][(int)map->pos.y] == 0) ?
			map->pos.x -= dir.x * move_speed : map->pos.x;
		map->pos.y = (board[(int)map->pos.x][(int)(map->pos.y - dir.y)] == 0) ?
			map->pos.y -= dir.y * move_speed : map->pos.y;
	}
}

void	strafe(t_map *map, int **board, t_complex dir)
{
	double	move_speed;

	move_speed = (map->run == 1) ? map->move_coef * 2 : map->move_coef;
	if (map->strafe_left)
	{
		map->pos.x = (board[(int)(map->pos.x - dir.y)][(int)map->pos.y] == 0) ?
			map->pos.x -= dir.y * move_speed : map->pos.x;
		map->pos.y = (board[(int)map->pos.x][(int)(map->pos.y + dir.x)] == 0) ?
			map->pos.y += dir.x * move_speed : map->pos.y;
	}
	if (map->strafe_right)
	{
		map->pos.x = (board[(int)(map->pos.x + dir.y)][(int)map->pos.y] == 0) ?
			map->pos.x += dir.y * move_speed : map->pos.x;
		map->pos.y = (board[(int)map->pos.x][(int)(map->pos.y - dir.x)] == 0) ?
			map->pos.y -= dir.x * move_speed : map->pos.y;
	}
}

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free_board(env->map);
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	exit(EXIT_SUCCESS);
}

int		key_press(int key, t_env *env)
{
	if (key == KEY_ESC)
		env->map->esc = 1;
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
	if (key == KEY_SHIFT)
		env->map->run = 1;
	if (key == KEY_SPACE)
		env->map->respawn = 1;
	if (key == KEY_M)
	{
		if (env->map->open_map == 0)
			env->map->open_map = 1;
		else
			env->map->open_map = 0;
	}
	if (key == KEY_O)
	{
		if (env->map->hide_map == 0)
			env->map->hide_map = 1;
		else
			env->map->hide_map = 0;
	}
	if (key == NUM_1)
	{
		if (env->map->texture_mode == 0)
			env->map->texture_mode = 1;
		else
			env->map->texture_mode = 0;
	}
	if (key == NUM_2)
	{
		if (env->map->map_zoom == 0)
			env->map->map_zoom = 1;
		else
			env->map->map_zoom = 0;
	}
	if (key == ARROW_UP)
		env->map->look_up = 1;
	if (key == ARROW_DOWN)
		env->map->look_down = 1;
	return (0);
}

int		key_release(int key, t_env *env)
{
	if (key == KEY_ESC)
		env->map->esc = 0;
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
	if (key == KEY_SPACE)
		env->map->respawn = 0;
	if (key == ARROW_UP)
		env->map->look_up = 0;
	if (key == ARROW_DOWN)
		env->map->look_down = 0;
	return (0);
}

int	multiple_events(t_env *env)
{
	if (env->map->esc == 1)
		close_program(env);
	if (env->map->up == 1 || env->map->down == 1)
		up_or_down(env->map, env->map->board, env->map->dir);
	if (env->map->left == 1|| env->map->right == 1)
	{
		env->map->mouse_left = 0;
		env->map->mouse_right = 0;
		left_or_right(env->map, env->map->rot_coef);
	}
	if (env->map->strafe_left == 1 || env->map->strafe_right == 1)
		strafe(env->map, env->map->board, env->map->dir);
	if (env->map->respawn == 1)
		set_values(env->map);
	if (env->map->open_map == 1)
		env->map->menu = 1;
	else if (env->map->open_map == 0)
		env->map->menu = 0;
	if (env->map->hide_map == 1)
		env->map->mm_switch = 1;
	else if (env->map->hide_map == 0)
		env->map->mm_switch = 0;
	if (env->map->texture_mode == 1)
		env->map->boo = 1;
	else if (env->map->texture_mode == 0)
		env->map->boo = 0;
	if (env->map->map_zoom == 1)
	{
		env->map->opt = 2;
		set_mmmap_values(env->map, env->map->opt);
	}
	else if (env->map->map_zoom == 0)
	{
		env->map->opt = 1;
		set_mmmap_values(env->map, env->map->opt);
	}
	if (env->map->look_up == 1 || env->map->look_down == 1)
		look_up_down(env->map);
	if (env->map->mouse_left == 1 || env->map->mouse_right == 1)
		left_or_right(env->map, env->map->rot_coef / 1.5);
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
	ray_casting(env, env->map);
	return (0);
}
