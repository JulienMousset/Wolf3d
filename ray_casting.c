/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:39:07 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/30 19:32:37 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_walls(t_map *map)
{
	if (map->ns_or_ew == 0)
		map->perp = (map->block.x - map->pos.x +
				(1 - map->step.x) / 2) / map->ray_dir.x;
	else
		map->perp = (map->block.y - map->pos.y +
				(1 - map->step.y) / 2) / map->ray_dir.y;
	map->line_height = (int)(H / map->perp);
	map->y_start = -map->line_height / 2 + map->h2;
	(map->y_start < 0) ? map->y_start = 0 : 0;
	map->y_end = map->line_height / 2 + map->h2;
	(map->y_end >= H) ? map->y_end = H - 1 : 0;
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
			map->ns_or_ew = 0;
		}
		else
		{
			map->side.y += map->delta.y;
			map->block.y += map->step.y;
			map->ns_or_ew = 1;
		}
		map->hit = ((map->board[map->block.x][map->block.y] > 0) &&
				(map->board[map->block.x][map->block.y] < FIRST_SPR) ) ? 1 : 0;
	}
}

void	set_dda_values(t_map *map)
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

void	ray_casting(t_env *env, t_map *map)
{
	int		x;

	x = 0;
	/*
	if (map->boo == 0)
	{
		draw_background(env);
		draw_sky(env, env->map);
	}
	*/
	draw_background(env);
	draw_sky(env, env->map);
	while (x < W)
	{
		map->camera_x = 2 * x / (double)W - 1;
		map->ray_dir.x = map->dir.x + map->plane.x * map->camera_x;
		map->ray_dir.y = map->dir.y + map->plane.y * map->camera_x;
		map->block.x = map->pos.x;
		map->block.y = map->pos.y;
		map->delta.x = fabs(1 / map->ray_dir.x);
		map->delta.y = fabs(1 / map->ray_dir.y);
		set_dda_values(map);
		dda(map);
		set_walls(map);
		map->z_buffer[x] = map->perp;
		map->id = map->board[map->block.x][map->block.y] - 1;
		draw_line(env, env->map, x, env->map->y_start);
		if (map->bool_tex == 1)
		{
			set_floor_casting(map);
			floor_casting(env, map, x);
			//set_ceil_casting(map);
			//ceil_casting(env, map, x);
		}
		x++;
	}
	if (map->bool_spr == 1)
		sprites(env, env->map);
	map->item_map ? draw_minimap(env, env->map) : 0;
	gui(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	text_gui(env);
	map->bool_menu ? menu(env) : 0;
}
