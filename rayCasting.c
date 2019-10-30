/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:57:05 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/30 18:15:37 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	i = 0;
	if ((x >= 0 && x <= W) && (y >= 0 && y <= H))
	{
		i = ((x * (env->bpp / 8)) + (y * env->s_l));
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

void		draw_line(t_env *env, int i, t_coord minMax, int color)
{
	while (minMax.x <= minMax.y)
	{
		put_pixel(env, i, minMax.x, color);
		minMax.x++;
	}
}

void		choose_color(t_map *map, int ip, int boo)
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
	map->color = color;
}

void	dda_values(t_map *map)
{

	//sideX, sideY: length of the ray from current pos to next x or y-side
	//deltaX, deltaY: length of the ray from one x, y-side to another
	//stepX, stepY: direction to decide x or y-side, (either +1 or -1)
	//hit = 0;  do we hit a wall?
	//side: was NS or EW side hit?
	
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


void	rayCasting(t_env *env, t_map *map)
{
	int		i;

	i = 0;
	while (i < W)
	{
		map->cameraX = 2 * i / (double)W - 1; //delta camera
		map->rayDir.x = map->dir.x + map->plane.x * map->cameraX; //dir of
		map->rayDir.y = map->dir.y + map->plane.y * map->cameraX; //each ray

		map->block.x = map->pos.x; //set our position as the intial block
		map->block.y = map->pos.y; //to after start checking furthers
		map->delta.x = abso(1 / map->rayDir.x); //the distance the ray has
	
		map->delta.y = abso(1 / map->rayDir.y); //to travel to the sides
		dda_values(map);
//		(i == 0) ? display_values(map) : 0;
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
//		printf("block[%d][%d]\n", map->block.x, map->block.y);
		if (map->boo == 0)
			map->perp = (map->block.x - map->pos.x +
					(1 - map->step.x) / 2) / map->rayDir.x;
		else
			map->perp = (map->block.y - map->pos.y +
					(1 - map->step.y) / 2) / map->rayDir.y;
//	map->pos = (t_complex) {.x = 0, .y = 0};
		map->wallHeight = (int)(H / map->perp);
		map->minMax.x = -map->wallHeight / 2 + H / 2;
		(map->minMax.x < 0) ? map->minMax.x = 0 : 0;
		map->minMax.y = map->wallHeight / 2 + H / 2;
		(map->minMax.y >= H) ? map->minMax.y = H - 1 : 0;
		choose_color(map, map->board[map->block.x][map->block.y], map->boo);
		draw_line(env, i, map->minMax, map->color);
//		printf("block[%d][%d]\n", map->block.x, map->block.y);
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
