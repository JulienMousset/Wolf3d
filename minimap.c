/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:10:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 17:31:19 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_mini_background(t_env *env, t_map *map)
{
	int			block;
	int			x;
	int			y;
	int			color;

	y = 0;

	color = BOI;
	block = map->mm_block_size;
	while (y < map->mm_size)
	{
		x = 0;
		while (x < map->mm_size)
		{
			color = BOI;
			if (y < block)
				color = north(env->map, x);
			if (y > map->mm_size - block)
				color = south(env->map, x);
			if (x < block)
				color = west(env->map, y);
			if (x > map->mm_size - block)
				color = east(env->map, y);
			put_pixel(env, map->mm_start.x + x, map->mm_start.y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_mini_background2(t_env *env, t_map *map)
{
	int			block;
	int			x;
	int			y;

	y = 0;

	block = map->mm_block_size;
	while (y < map->mm_size)
	{
		x = 0;
		while (x < map->mm_size)
		{
			if (y < block || y > map->mm_size - block ||
					x < block || x > map->mm_size - block)
				put_pixel(env, map->mm_start.x + x, map->mm_start.y + y, 0);
			else
				put_pixel(env, map->mm_start.x + x, map->mm_start.y + y, BOI);
			x++;
		}
		y++;
	}
}

int		mm_color(t_map *map, int id, int i)
{
	if (map->mm_color)
		return (choose_color(id, i));
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
	y = 0;
	while (y < map->mm_block_size)
	{
		x = 0;
		while (x < map->mm_block_size)
		{
			if (((coord.x + x + xx < map->mm_end.x) &&
						(coord.x + x + xx > map->mm_start.x)) &&
					((coord.y + y + yy < map->mm_end.y) &&
					 (coord.y + y + yy > map->mm_start.y)))
				put_pixel(env, coord.x + x + xx, coord.y + y + yy,
						color);
			x++;
		}
		y++;
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
			if((c.x + x >= 0) && (c.x + x < map->nb_columns) &&
					(c.y + y >= 0) && (c.y + y < map->nb_lines) &&
					map->board[c.y + y][c.x + x] &&
					map->board[c.y + y][c.x + x] < 6)
				put_n_pixel(env, x, y, map->board[c.y + y][c.x + x]);
			if (c.x + x == (int)map->pos.y && c.y + y == (int)map->pos.x)
				put_n_pixel(env, x, y, 0);
			x++;
		}
		y++;
	}
}
