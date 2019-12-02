/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:19:23 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/02 19:09:40 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_mini_sprite(t_env *env, t_map *map, int id, int margin_y)
{
	t_coord		p;
	t_coord		tex;
	int			i;
	int			size;

	p = (t_coord) {.x = 0, .y = 0};
	size = (id == ID_CONTAINER_RED - 1 || id == ID_CONTAINER_RED_HALF - 1 ||
			id == ID_CONTAINER_EMPTY - 1) ? TS * 3 : TS * 2;
	while (p.y < size)
	{
		tex.y = p.y * TS / size;
		p.x = 0;
		while (p.x < size)
		{
			tex.x = p.x * TS / size;
			i = ((tex.x * env->t[8].bpp / 8) + tex.y * env->t[8].s_l);
			ft_memcpy(&map->color_str, &env->t[id].data_addr[i], sizeof(int));
			map->color = (int)map->color_str;
			if (map->color != 0)
				put_pixel(env, map->gui_margin.x + p.x, margin_y + p.y, map->color);
			p.x++;
		}
		p.y++;
	}
}

void	print_hearts(t_env *env, t_map *map)
{
	t_coord		c;
	int			i;

	c = (t_coord) {.x = 0, .y = 0};
	i = -1;
	while (++i <  map->pick_heart / 2)
	{
	print_mini_sprite(env, map, ID_CONTAINER_RED - 1, map->gui_margin.y);
	map->gui_margin.x += TS + 20;
	}
	i = -1;
	while (++i <  map->pick_heart % 2)
	{
	print_mini_sprite(env, map, ID_CONTAINER_RED_HALF - 1, map->gui_margin.y);
	map->gui_margin.x += TS + 20;
	}
	i = -1;
	while (++i <  map->container - (map->pick_heart / 2 + map->pick_heart % 2))
	{
	print_mini_sprite(env, map, ID_CONTAINER_EMPTY - 1, map->gui_margin.y);
	map->gui_margin.x += TS + 20;
	}
	map->gui_margin.x = - TS / 2;
}

int		size(t_map *map, int n)
{
	return (map->gui_margin.y + TS * 0.8 * n);
}

void	gui(t_env *env, t_map *map)
{
	int		n;

	n = 2;
	print_hearts(env, env->map);
	print_mini_sprite(env, map, ID_COIN - 1, size(map, n++));
	print_mini_sprite(env, map, ID_KEY - 1, size(map, n++));
	n += 1;
	if (map->item_map)
		print_mini_sprite(env, map, ID_MAP - 1, size(map, n++));
	if (map->item_heels)
		print_mini_sprite(env, map, ID_HEELS - 1, size(map, n++));
	if (map->item_poly)
		print_mini_sprite(env, map, ID_POLY - 1, size(map, n++));
	if (map->item_ipecac)
		print_mini_sprite(env, map, ID_IPECAC - 1, size(map, n++));
	if (map->item_godhead)
		print_mini_sprite(env, map, ID_GODHEAD - 1, size(map, n++));
}
