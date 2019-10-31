/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:02:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/31 18:23:03 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	left_or_right(int key, t_map *map)
{
	double	old_dir;
	double	old_plane;
	double	rot_speed;

	old_dir = map->dir.x;
	old_plane = map->plane.x;
	if (key == KEY_D)
		rot_speed = -1;
	else
		rot_speed = 1;
	map->dir.x = map->dir.x * cos(rot_speed) - map->dir.y * sin(rot_speed);
	map->dir.y = old_dir * sin(rot_speed) + map->dir.y * cos(rot_speed);
	map->plane.x = map->plane.x * cos(rot_speed)
		- map->plane.y * sin(rot_speed);
	map->plane.y = old_plane * cos(rot_speed) + map->plane.y * cos(rot_speed);
}

void	up_or_down(int key, t_map *map, int **board, t_complex dir)
{
	if (key == KEY_W)
	{
		map->pos.x = (board[(int)(map->pos.x + dir.x)][(int)map->pos.y] == 0) ?
			map->pos.x += dir.x * MOVE_SPEED : map->pos.x;
		map->pos.y = (board[(int)map->pos.x][(int)(map->pos.y + dir.y)] == 0) ?
			map->pos.y += dir.y * MOVE_SPEED: map->pos.y;
	}
	else if (key == KEY_S)
	{
		map->pos.x = (board[(int)(map->pos.x - dir.x)][(int)map->pos.y] == 0) ?
			map->pos.x -= dir.x * MOVE_SPEED : map->pos.x;
		map->pos.y = (board[(int)map->pos.x][(int)(map->pos.y - dir.y)] == 0) ?
			map->pos.y -= dir.y * MOVE_SPEED : map->pos.y;
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

int		key_press(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == KEY_ESC)
		close_program(env);
	else if (key == KEY_W || key == KEY_S)
		up_or_down(key, env->map, env->map->board, env->map->dir);
	else if (key == KEY_A || key == KEY_D)
		left_or_right(key, env->map);
	ray_casting(env, env->map);
	return (0);
}
