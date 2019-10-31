/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:57:05 by pasosa-s          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/31 13:20:52 by jmousset         ###   ########.fr       */
=======
/*   Updated: 2019/10/31 14:25:08 by pasosa-s         ###   ########.fr       */
>>>>>>> 85082e6a4112a158c4d12856e511add47c5f3f86
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	walls(t_map *map)
{
	if (map->boo == 0)
		map->perp = (map->block.x - map->pos.x +
				(1 - map->step.x) / 2) / map->ray_dir.x;
	else
		map->perp = (map->block.y - map->pos.y +
				(1 - map->step.y) / 2) / map->ray_dir.y;
	map->wall_height = (int)(H / map->perp);
	//Change min_max variable name?
	map->min_max.x = -map->wall_height / 2 + H / 2;
	(map->min_max.x < 0) ? map->min_max.x = 0 : 0;
	map->min_max.y = map->wall_height / 2 + H / 2;
	(map->min_max.y >= H) ? map->min_max.y = H - 1 : 0;
}

void	dda(t_map *map)
{
	map->hit = 0;
	while (!map->hit)
	{
		if (map->side.x < map->side.y)
		{
			map->side.x += map->delta.x;
			map->block.x += map->step.x;
			//Let's change the boo variable name plz 😂
			map->boo = 0;
		}
		else
		{
			map->side.y += map->delta.y;
			map->block.y += map->step.y;
			map->boo = 1;
		}
		map->hit = (map->board[map->block.x][map->block.y] > 0) ? 1 : 0;
	}
}

void	dda_values(t_map *map)
{
	if (map->ray_dir.x < 0)
	{
		map->step.x = -1;
		map->side.x = (map->pos.x - map->block.x) * map->delta.x;
	}
	else
	{
		map->step.x = 1;
		map->side.x = (map->block.x + 1.0 - map->pos.x) * map->delta.x;
	}
	if (map->ray_dir.y < 0)
	{
		map->step.y = -1;
		map->side.y = (map->pos.y - map->block.y) * map->delta.y;
	}
	else
	{
		map->step.y = 1;
		map->side.y = (map->block.y + 1.0 - map->pos.y) * map->delta.y;
	}
}

void	display_result(t_env *env, t_map *map)
{
	map->old_time = map->time;
	map->time = get_time();
	map->frame_time = (map->time - map->old_time) / 1000.0;
	printf("fps : %f\n", map->frame_time);
	map->move_speed = map->frame_time * 5.0;
	map->rot_speed = map->frame_time * 3.0;
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	menu(env);

}

void	ray_casting(t_env *env, t_map *map)
{
	int		i;

	i = 0;
	draw_background(env);
	while (i < W)
	{
		map->camera_x = 2 * i / (double)W - 1;
		map->ray_dir.x = map->dir.x + map->plane.x * map->camera_x;
		map->ray_dir.y = map->dir.y + map->plane.y * map->camera_x;
		map->block.x = map->pos.x;
		map->block.y = map->pos.y;
		//Why not use the math lib function fabs?
		map->delta.x = abso(1 / map->ray_dir.x);
		map->delta.y = abso(1 / map->ray_dir.y);
		dda_values(map);
		dda(map);
		walls(map);
		choose_color(map, map->board[map->block.x][map->block.y], map->boo);
		draw_line(env, i, map->min_max, map->color);
		i++;
	}
	display_result(env, env->map);
}
