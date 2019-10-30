/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:57:05 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/30 20:30:34 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dda_values(t_map *map)
{
	if (map->rayDir.x < 0)
	{
		map->step.x = -1;
		map->side.x = (map->pos.x - map->block.x) * map->delta.x;
	}
	else
	{
		map->step.x = 1;
		map->side.x = (map->block.x + 1.0 - map->pos.x) * map->delta.x;
	}
	if (map->rayDir.y < 0)
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
				(1 - map->step.x) / 2) / map->rayDir.x;
	else
		map->perp = (map->block.y - map->pos.y +
				(1 - map->step.y) / 2) / map->rayDir.y;
	map->wallHeight = (int)(H / map->perp);
	map->minMax.x = -map->wallHeight / 2 + H / 2;
	(map->minMax.x < 0) ? map->minMax.x = 0 : 0;
	map->minMax.y = map->wallHeight / 2 + H / 2;
	(map->minMax.y >= H) ? map->minMax.y = H - 1 : 0;
}

void	ray_casting(t_env *env, t_map *map)
{
	int		i;

	i = 0;
	draw_background(env);
	while (i < W)
	{
		map->cameraX = 2 * i / (double)W - 1;
		map->rayDir.x = map->dir.x + map->plane.x * map->cameraX;
		map->rayDir.y = map->dir.y + map->plane.y * map->cameraX;
		map->block.x = map->pos.x;
		map->block.y = map->pos.y;
		map->delta.x = abso(1 / map->rayDir.x);
		map->delta.y = abso(1 / map->rayDir.y);
		dda_values(map);
		dda(map);
		walls(map);
		choose_color(map, map->board[map->block.x][map->block.y], map->boo);
		draw_line(env, i, map->minMax, map->color);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	menu(env);
}
