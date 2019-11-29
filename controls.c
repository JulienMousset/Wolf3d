/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:02:20 by pasosa-s          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/11/29 13:25:26 by pasosa-s         ###   ########.fr       */
=======
/*   Updated: 2019/11/29 13:15:35 by jmousset         ###   ########.fr       */
>>>>>>> f08c0e8fcc48388037c8b2949271ac0cc3cb9508
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
	t_coord	add;
	t_coord	rest;
	double	move_speed;

	move_speed = (map->run == 1) ? map->move_coef * 3 : map->move_coef;
	if (map->up == 1)
	{
		add.x = (int)(map->pos.x + dir.x);
		add.y = (int)(map->pos.y + dir.y);
		map->pos.x = is_walkable(map, board[add.x][(int)map->pos.y], add.x, (int)map->pos.y) ?
			map->pos.x += dir.x * move_speed : map->pos.x;
		map->pos.y = is_walkable(map, board[(int)map->pos.x][add.y], (int)map->pos.x, add.y) ?
			map->pos.y += dir.y * move_speed : map->pos.y;
	}
	if (map->down == 1)
	{
		rest.x = (int)(map->pos.x - dir.x);
		rest.y = (int)(map->pos.y - dir.y);
		map->pos.x = is_walkable(map, board[rest.x][(int)map->pos.y], rest.x, (int)map->pos.y) ?
			map->pos.x -= dir.x * move_speed : map->pos.x;
		map->pos.y = is_walkable(map, board[(int)map->pos.x][rest.y], (int)map->pos.x, rest.y) ?
			map->pos.y -= dir.y * move_speed : map->pos.y;
	}
}

void	strafe(t_map *map, int **board, t_complex dir)
{
	t_coord	left;
	t_coord	right;
	double	move_speed;

	move_speed = (map->run == 1) ? map->move_coef * 2 : map->move_coef;
	if (map->strafe_left)
	{
		left.x = (int)(map->pos.x - dir.y);
		left.y = (int)(map->pos.y + dir.x);
		map->pos.x = is_walkable(map, board[left.x][(int)map->pos.y], left.x, (int)map->pos.y) ?
			map->pos.x -= dir.y * move_speed : map->pos.x;
		map->pos.y = is_walkable(map, board[(int)map->pos.x][left.y], (int)map->pos.x, left.y) ?
			map->pos.y += dir.x * move_speed : map->pos.y;
	}
	if (map->strafe_right)
	{
		right.x = (int)(map->pos.x + dir.y);
		right.y = (int)(map->pos.y - dir.x);
		map->pos.x = is_walkable(map, board[right.x][(int)map->pos.y], right.x, (int)map->pos.y) ?
			map->pos.x += dir.y * move_speed : map->pos.x;
		map->pos.y = is_walkable(map, board[(int)map->pos.x][right.y], (int)map->pos.x, right.y) ?
			map->pos.y -= dir.x * move_speed : map->pos.y;
	}
}

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_tabdel(env->map->board, env->map->nb_lines);
	ft_tabdel(env->map->copy, env->map->nb_lines);
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
	if (key == KEY_SHIFT && env->map->bool_sprint)
		env->map->run = 1;
	if (key == KEY_SPACE)
	{
		set_values(env->map);
		copy_board(env->map);
		create_sprites_array(env->map);
	}
	if (key == KEY_M)
	{
		if (env->map->open_map == 0)
			env->map->open_map = 1;
		else
			env->map->open_map = 0;
	}
	if (key == NUM_1)
		env->map->bool_tex = env->map->bool_tex ? 0 : 1;
	if (key == NUM_2 && env->map->bool_mm)
	{
		env->map->opt = env->map->opt == 1 ? 2 : 1;
		set_mmmap_values(env->map, env->map->opt);
	}
	if (key == NUM_3)
		env->map->bool_spr = env->map->bool_spr ? 0 : 1;
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
	ray_casting(env, env->map);
	return (0);
}
