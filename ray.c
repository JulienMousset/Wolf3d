/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:26:29 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/28 19:35:05 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		choose_color(int ip, int boo)
{
	int		color;

	if (ip == 1)
		color = 0xFF0000;
	else if (ip == 2)
		color = 0x00FF00;
	else
		color = 0x0000FF;
	if (boo == 1)
		color = color / 2;
	return (color);
}

void	dda_values(t_map *map)
{
	if (map->raydir.x < 0)
	{
		map->step.x = -1;
		map->side.x = (map->pos.x - map->block.x) * map->delta.x;
	}
	else
	{
		map->step.x = 1;
		map->side.x = (map->block.x + 1.0 - map->pos.x) * map->delta.x;
	}
	if (map->raydir.y < 0)
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


void	casting(t_map *map)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		map->sign = 2 * i / (double)WIDTH - 1;
		map->raydir.x = map->dir.x + map->plane.x * map->sign;
		map->raydir.y = map->dir.y + map->plane.y * map->sign;
		map->block.x = map->pos.x;
		map->block.y = map->pos.y;
		map->delta.x = abso(1 / map->raydir.x);
		map->delta.y = abso(1 / map->raydir.y);
		dda_values(map);
//		(i == 0) ? display_values(map) : 0;
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
//		printf("block[%d][%d]\n", map->block.x, map->block.y);
		if (map->boo == 0)
			map->perp = (map->block.x - map->pos.x +
					(1 - map->step.x) / 2) / map->raydir.x;
		else
			map->perp = (map->block.y - map->pos.y +
					(1 - map->step.y) / 2) / map->raydir.y;
	map->pos = (t_complex) {.x = 0, .y = 0};
		map->height = (int)(HEIGHT / map->perp);
		map->minmax.x = -map->height / 2 + HEIGHT / 2;
		(map->minmax.x < 0) ? map->minmax.x = 0 : 0;
		map->minmax.y = map->height / 2 + HEIGHT / 2;
		(map->minmax.y >= HEIGHT) ? map->minmax.y = HEIGHT - 1 : 0;
		choose_color(map->board[map->block.x][map->block.y], map->boo);
		i++;
	}	
}

void	ray(t_env *mlx)
{
	casting(mlx->map);
}
