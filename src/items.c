/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:18:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 19:19:16 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		in_array(t_map *map, int x, int y)
{
	int		i;

	i = 0;
	while (i < map->nb_sprites)
	{
		if (map->s[i].x == x + 0.5 && map->s[i].y == y + 0.5)
			return (1);
		i++;
	}
	return (0);
}

void	interact_solid(t_map *map, int id)
{
	if (id == ID_BLOOD_MACHINE && map->pick_heart)
	{
		map->pick_heart--;
		map->pick_coin++;
	}
	else if (id == ID_BEGGAR_COIN && map->pick_coin)
	{
		map->pick_coin--;
		randomy(0, 2) == 0 ? map->pick_key++ : 0;
	}
	else if (id == ID_BEGGAR_KEY && map->pick_key)
	{
		map->pick_key--;
		map->pick_coin++;
	}
	else if (id == ID_BEGGAR_HEART && map->pick_heart)
	{
		map->pick_heart--;
		map->i = randomy(0, 2);
		if (map->i == 1)
			map->pick_key++;
		else if (map->i == 2)
			map->pick_coin += 2;
	}
}

void	trade(t_map *map, int **board)
{
	int		id;

	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	if (id >= 47 && id <= 50)
		interact_solid(map, id);
	if (map->pick_coin > 99)
		map->pick_coin = 99;
	if (map->pick_key > 99)
		map->pick_key = 99;
}

void	curse_door(t_map *map, int id)
{
	if (id != ID_CDOOR && map->prev_id.x != ID_CDOOR &&
			map->prev_id.y == ID_CDOOR && !map->item_mantle)
		map->pick_heart--;
	map->prev_id.y = map->prev_id.x;
	map->prev_id.x = id;
}

int		is_walkable(t_map *map, int id, int x, int y)
{
	if (is_pickable(map, id) || is_shop(map, id, map->pick_coin) ||
			is_destroyable(map, id))
		realloc_array(map, x, y, id);
	if (is_door(map, id, x, y))
		return (1);
	curse_door(map, id);
	return ((is_walk(map, id)) ? 1 : 0);
}
