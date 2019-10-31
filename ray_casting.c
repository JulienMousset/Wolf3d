/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:57:05 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/31 12:27:58 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void	dda(t_map *map)
{
	map->hit = 0;
	while (!map->hit)
	{
		if (map->side.x < map->side.y)
		{
			map->side.x += map->delta.x;
			map->block.x += map->step.x;
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

void	walls(t_map *map)
{
	if (map->boo == 0)
		map->perp = (map->block.x - map->pos.x +
				(1 - map->step.x) / 2) / map->ray_dir.x;
	else
		map->perp = (map->block.y - map->pos.y +
				(1 - map->step.y) / 2) / map->ray_dir.y;
	map->wall_height = (int)(H / map->perp);
	map->min_max.x = -map->wall_height / 2 + H / 2;
	(map->min_max.x < 0) ? map->min_max.x = 0 : 0;
	map->min_max.y = map->wall_height / 2 + H / 2;
	(map->min_max.y >= H) ? map->min_max.y = H - 1 : 0;
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
		map->delta.x = abso(1 / map->ray_dir.x);
		map->delta.y = abso(1 / map->ray_dir.y);
		dda_values(map);
		dda(map);
		walls(map);
		choose_color(map, map->board[map->block.x][map->block.y], map->boo);
		draw_line(env, i, map->min_max, map->color);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	menu(env);
}
