/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:26:27 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/13 19:07:27 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_tabdel(env->map->board, env->map->nb_lines);
	ft_tabdel(env->map->board_cpy, env->map->nb_lines);
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	exit(EXIT_SUCCESS);
}

void	look_up_down(t_map *map)
{
	if (map->look_up == 1 && map->h2 < map->max)
		map->h2_coef += 25;
	if (map->look_down == 1 && map->h2 > map->min + 25)
		map->h2_coef -= 25;
	map->h2 = H / 2 + map->h2_coef;
	if (map->h2 > map->max)
		map->h2 = map->max;
	if (map->h2 < map->min)
		map->h2 = map->min;
}

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
	map->plane.x = map->plane.x * cos(rot_speed) -
		map->plane.y * sin(rot_speed);
	map->plane.y = old_plane * sin(rot_speed) + map->plane.y * cos(rot_speed);
}

void	up_or_down(t_map *map, int **board, t_complex dir)
{
	t_coord	add;
	double	move_speed;

	move_speed = (map->run == 1) ? map->move_coef * 1.75 : map->move_coef;
	if (map->up == 1)
	{
		add.x = (map->pos.x + dir.x * map->move_coef * SCALE_MS);
		add.y = (map->pos.y + dir.y * map->move_coef * SCALE_MS);
		if (is_walkable(map, board[add.x][(int)map->pos.y], add.x, map->pos.y))
			map->pos.x += dir.x * move_speed;
		if (is_walkable(map, board[(int)map->pos.x][add.y], map->pos.x, add.y))
			map->pos.y += dir.y * move_speed;
	}
	if (map->down == 1)
	{
		add.x = (map->pos.x - dir.x * map->move_coef * SCALE_MS);
		add.y = (map->pos.y - dir.y * map->move_coef * SCALE_MS);
		if (is_walkable(map, board[add.x][(int)map->pos.y], add.x, map->pos.y))
			map->pos.x -= dir.x * move_speed;
		if (is_walkable(map, board[(int)map->pos.x][add.y], map->pos.x, add.y))
			map->pos.y -= dir.y * move_speed;
	}
}

void	strafe(t_map *map, int **board, t_complex dir)
{
	t_coord	add;
	double	move_speed;

	move_speed = (map->run == 1) ? map->move_coef * 1.75 : map->move_coef;
	if (map->strafe_left)
	{
		add.x = (map->pos.x - dir.y * map->move_coef * SCALE_MS);
		add.y = (map->pos.y + dir.x * map->move_coef * SCALE_MS);
		if (is_walkable(map, board[add.x][(int)map->pos.y], add.x, map->pos.y))
			map->pos.x -= dir.y * move_speed;
		if (is_walkable(map, board[(int)map->pos.x][add.y], map->pos.x, add.y))
			map->pos.y += dir.x * move_speed;
	}
	if (map->strafe_right)
	{
		add.x = (map->pos.x + dir.y * map->move_coef * SCALE_MS);
		add.y = (map->pos.y - dir.x * map->move_coef * SCALE_MS);
		if (is_walkable(map, board[add.x][(int)map->pos.y], add.x, map->pos.y))
			map->pos.x += dir.y * move_speed;
		if (is_walkable(map, board[(int)map->pos.x][add.y], map->pos.x, add.y))
			map->pos.y -= dir.x * move_speed;
	}
}
