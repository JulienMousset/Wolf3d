/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:25:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 15:13:43 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		mm_color(t_map *map, int id, int i)
{
	if (map->mm_color)
		return (choose_color(map, id, i));
	else
		return (0);
}

void	put_n_pixel(t_env *env, int xx, int yy, int id)
{
	t_map	*map;
	int		color;
	int		x;
	int		y;
	t_coord	coord;

	map = env->map;
	color = (id == 0) ? MARBLE : mm_color(env->map, id, 0);
	xx *= map->mm_block_size;
	yy *= map->mm_block_size;
	coord.x = map->mm_center.x - map->mm_vis / 2 * map->mm_block_size;
	coord.y = map->mm_center.y - map->mm_vis / 2 * map->mm_block_size;
	y = -1;
	while (++y < map->mm_block_size)
	{
		x = -1;
		while (++x < map->mm_block_size)
		{
			if (((coord.x + x + xx < map->mm_end.x) && (coord.x + x +
							xx > map->mm_start.x)) &&
					((coord.y + y + yy < map->mm_end.y) && (coord.y + y +
						yy > map->mm_start.y)))
				put_pixel(env, coord.x + x + xx, coord.y + y + yy, color);
		}
	}
}

void	draw_mini_background(t_env *env, t_map *map)
{
	int		block;
	int		x;
	int		y;
	int		color;

	block = map->mm_block_size;
	y = -1;
	while (++y < map->mm_size)
	{
		x = -1;
		while (++x < map->mm_size)
		{
			color = MARRON_0;
			if (y < block)
				color = north(env->map, x);
			if (y > map->mm_size - block)
				color = south(env->map, x);
			if (x < block)
				color = west(env->map, y);
			if (x > map->mm_size - block)
				color = east(env->map, y);
			put_pixel(env, map->mm_start.x + x, map->mm_start.y + y, color);
		}
	}
}

void	draw_minimap(t_env *env, t_map *map)
{
	int		x;
	int		y;
	t_coord	c;

	draw_mini_background(env, map);
	c.x = map->pos.y - map->mm_vis / 2;
	c.y = map->pos.x - map->mm_vis / 2;
	y = 0;
	while (y < map->mm_vis)
	{
		x = 0;
		while (x < map->mm_vis)
		{
			if ((c.x + x >= 0) && (c.x + x < map->nb_columns) &&
					(c.y + y >= 0) && (c.y + y < map->nb_lines) &&
					map->board[c.y + y][c.x + x] &&
					map->board[c.y + y][c.x + x] <= LAST_WALL)
				put_n_pixel(env, x, y, map->board[c.y + y][c.x + x]);
			if (c.x + x == (int)map->pos.y && c.y + y == (int)map->pos.x)
				put_n_pixel(env, x, y, 0);
			x++;
		}
		y++;
	}
}
