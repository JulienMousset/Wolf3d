/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:13:59 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/10 19:45:46 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_large_spr(int id)
{
	return ((id == ID_CONTAINER_RED - 1 || id == ID_CONTAINER_RED_HALF - 1 ||
				id == ID_CONTAINER_EMPTY - 1 || id == ID_SHIFT_ON - 1) ? 1 : 0);
}

void	print_mini_sprite(t_env *env, t_map *map, int id, t_coord margin)
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

t_coord		size(t_map *map, int id, int n)
{
	t_coord 	c;

	if (id == 1)
	{
		c.x = map->gui_margin.x;
		c.y = map->gui_margin.y + TS * 0.8 * n;
	}
	if (id == 2)
	{
		c.x = map->gui_margin.x;
		c.y = map->gui_margin.y;
	}
	if (id == 3)
	{
		c.x = 10;
		c.y = per(H, 95);
	}
	if (id == 4)
	{
		c.x = 20;
		c.y = per(H, 96);
	}
	return (c);
}

void	print_hearts(t_env *env, t_map *map)
{
	int			i;

	i = -1;
	map->gui_margin.x = - TS / 2;
	while (++i <  map->pick_heart / 2)
	{
		print_mini_sprite(env, map, ID_CONTAINER_RED - 1, size(map, 2, 0));
		map->gui_margin.x += TS + 20;
	}
	i = -1;
	while (++i <  map->pick_heart % 2)
	{
		print_mini_sprite(env, map, ID_CONTAINER_RED_HALF - 1, size(map, 2, 20));
		map->gui_margin.x += TS + 20;
	}
	i = -1;
	while (++i <  map->container - (map->pick_heart / 2 + map->pick_heart % 2))
	{
		print_mini_sprite(env, map, ID_CONTAINER_EMPTY - 1, size(map, 2, 20));
		map->gui_margin.x += TS + 20;
	}
	map->gui_margin.x = - TS / 2;
}

void	gui(t_env *env, t_map *map)
{
	int		n;

	n = 2;
	print_hearts(env, env->map);
	print_mini_sprite(env, map, ID_COIN - 1, size(map, 1, n++));
	print_mini_sprite(env, map, ID_KEY - 1, size(map, 1, n++));
	n += 1;
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
	if (map->item_heels && map->run)
		print_mini_sprite(env, map, ID_SHIFT_ON - 1, size(map, 3, 0));
	else if (map->item_heels)
		print_mini_sprite(env, map, ID_SHIFT_OFF - 1, size(map, 4, 0));
	/*
	if (map->board[(int)map->pos.x][(int)map->pos.y] >= FIRST_SHOP &&
			map->board[(int)map->pos.x][(int)map->pos.y] <= LAST_SHOP &&
			map->pick_coin < 15)
	{
		c.x = W / 2;
		c.y = H / 2;
		print_mini_sprite(env, env->map, ID_PRICE_TAG_15 - 1, c);
	}
	*/
}
