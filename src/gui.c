/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:46:13 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 14:08:17 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int			is_large_spr(int id)
{
	return ((id == ID_CONTAINER_RED - 1 || id == ID_CONTAINER_HALF - 1 ||
				id == ID_CONTAINER_EMPTY - 1 || id == ID_SHIFT_ON - 1 ||
				id == ID_TAG_5 - 1 || id == ID_TAG_15 - 1 ||
				id == ID_TAG_99 - 1 || id == ID_HANGING - 1 ||
				id == ID_GUPPY - 1) ? 1 : 0);
}

void		print_mini_sprite(t_env *env, t_map *map, int id, t_coord margin)
{
	t_coord		p;
	t_coord		tex;
	int			i;
	int			size;

	p = (t_coord) {.x = 0, .y = 0};
	size = is_large_spr(id) ? TS * 3 : TS * 2;
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
				put_pixel(env, margin.x + p.x, margin.y + p.y, map->color);
			p.x++;
		}
		p.y++;
	}
}

void		print_items_gui(t_env *env, t_map *map, int n)
{
	if (map->item_map)
		print_mini_sprite(env, map, ID_MAP - 1, size(map, 1, n++));
	if (map->item_heels)
		print_mini_sprite(env, map, ID_HEELS - 1, size(map, 1, n++));
	if (map->item_poly)
		print_mini_sprite(env, map, ID_POLY - 1, size(map, 1, n++));
	if (map->item_ipecac)
		print_mini_sprite(env, map, ID_IPECAC - 1, size(map, 1, n++));
	if (map->item_godhead)
		print_mini_sprite(env, map, ID_GODHEAD - 1, size(map, 1, n++));
	if (map->item_quarter)
		print_mini_sprite(env, map, ID_QUARTER - 1, size(map, 1, n++));
	if (map->item_dinner)
		print_mini_sprite(env, map, ID_DINNER - 1, size(map, 1, n++));
	if (map->item_xray)
		print_mini_sprite(env, map, ID_XRAY - 1, size(map, 1, n++));
	if (map->item_axe)
		print_mini_sprite(env, map, ID_AXE - 1, size(map, 1, n++));
	if (map->item_mantle)
		print_mini_sprite(env, map, ID_MANTLE - 1, size(map, 1, n++));
	if (map->item_candle == 5)
		print_mini_sprite(env, map, ID_CANDLE - 1, size(map, 1, n++));
}

void		print_hearts(t_env *env, t_map *map)
{
	int			i;

	i = -1;
	map->gui_margin.x = -TS / 2;
	while (++i < map->pick_heart / 2)
	{
		print_mini_sprite(env, map, ID_CONTAINER_RED - 1, size(map, 2, 0));
		map->gui_margin.x += TS + 20;
	}
	i = -1;
	while (++i < map->pick_heart % 2)
	{
		print_mini_sprite(env, map, ID_CONTAINER_HALF - 1, size(map, 2, 20));
		map->gui_margin.x += TS + 20;
	}
	i = -1;
	while (++i < map->container - (map->pick_heart / 2 + map->pick_heart % 2))
	{
		print_mini_sprite(env, map, ID_CONTAINER_EMPTY - 1, size(map, 2, 20));
		map->gui_margin.x += TS + 20;
	}
	map->gui_margin.x = -TS / 2;
}

void		gui(t_env *env, t_map *map, int **board)
{
	int		n;
	int		id;

	n = 2;
	print_hearts(env, env->map);
	print_mini_sprite(env, map, ID_COIN - 1, size(map, 1, n++));
	print_mini_sprite(env, map, ID_KEY - 1, size(map, 1, n++));
	n += 1;
	print_items_gui(env, map, n);
	if (map->item_heels && map->run)
		print_mini_sprite(env, map, ID_SHIFT_ON - 1, size(map, 3, 0));
	else if (map->item_heels)
		print_mini_sprite(env, map, ID_SHIFT_OFF - 1, size(map, 4, 0));
	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	if (id >= 21 && id <= 23)
		print_mini_sprite(env, map, ID_TAG_99 - 1, size(map, 5, 0));
	else if (id >= 24 && id <= 28)
		print_mini_sprite(env, map, ID_TAG_15 - 1, size(map, 5, 0));
	else if (id >= 51 && id <= 52)
		print_mini_sprite(env, map, ID_TAG_5 - 1, size(map, 5, 0));
}
