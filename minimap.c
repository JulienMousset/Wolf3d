/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:10:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/01 22:14:55 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_mini_background(t_env *env, t_map *map)
{
	int			x;
	int			y;

	map->mm_coord.x = W - per(W, 7) - map->mm_size;
	map->mm_coord.y = per(H, 5);
	y = 0;
	while (y < map->mm_size)
	{
		x = 0;
		while (x < map->mm_size)
		{
			put_pixel(env, map->mm_coord.x + x, map->mm_coord.y + y, GREY4);
			x++;
		}
		y++;
	}
}

void	put_n_pixel(t_env *env, int xx, int yy, int id)
{
	t_map	*map;
	int		color;
	int		x;
	int		y;

	map = env->map;
	if (id == 0)
		color = PINK;
	else
		color = choose_color(id, 0);
	xx *= map->mm_block_size;
	yy *= map->mm_block_size;
	y = 0;
	while (y < map->mm_block_size)
	{
		x = 0;
		while (x < map->mm_block_size)
		{
			if ((map->mm_coord.x + x + xx < W) && (map->mm_coord.y + y + yy < H))
				put_pixel(env, map->mm_coord.x + x + xx, map->mm_coord.y + y + yy,
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
	c.x = map->pos.x - map->mm_vis / 2;
	c.y = map->pos.y - map->mm_vis / 2;
	y = 0;
	while (y < map->mm_vis)
	{
		x = 0;
		while (x < map->mm_vis)
		{
			if((c.x + x >= 0) && (c.x + x < map->nb_columns) &&
					(c.y + y >= 0) && (c.y + y < map->nb_lines) &&
					map->board[c.x + x][c.y + y])
				put_n_pixel(env, x, y, map->board[c.x + x][c.y + y]);
			if (c.x + x == (int)map->pos.x && c.y + y == (int)map->pos.y)
				put_n_pixel(env, x, y, 0);
			x++;
		}
		y++;
	}
}
