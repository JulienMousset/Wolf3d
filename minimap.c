/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:10:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/15 16:10:16 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_mini_background(t_env *env, t_map *map)
{
	int			x;
	int			y;

	y = 0;
	while (y < map->mm_size)
	{
		x = 0;
		while (x < map->mm_size)
		{
			put_pixel(env, map->mm_start.x + x, map->mm_start.y + y, GREY4);
			x++;
		}
		y++;
	}
}

void	put_n_pixel(t_env *env, int xx, int yy, int id, t_coord c)
{
	t_map	*map;
	int		color;
	int		x;
	int		y;
	t_coord	coord;

	(void)c;
	map = env->map;
	color = (id == 0) ? PINK : choose_color(id, 0);
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
					map->board[c.y + y][c.x + x])
				put_n_pixel(env, x, y, map->board[c.y + y][c.x + x], c);
			if (c.x + x == (int)map->pos.y && c.y + y == (int)map->pos.x)
				put_n_pixel(env, x, y, 0, c);
			x++;
		}
		y++;
	}
}
