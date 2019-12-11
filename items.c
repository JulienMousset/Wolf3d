/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:18:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 15:35:23 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_pickable(t_map *map, int id)
{
	return (((id >= FIRST_FREE && id <= LAST_FREE) || ((id == ID_RHEART ||
						id == ID_RHEART_HALF) &&
					map->pick_heart < map->container * 2)) ? 1 : 0);
}

int		is_walk(int id)
{
	return ((id == 0 || id == ID_SECRET1 || id == ID_SECRET2 ||
				id == ID_SECRET3 || id == ID_HEART_SHOP || id == ID_KEY_SHOP ||
				(id >= FIRST_WALK && id <= LAST_WALK)) ?
			1 : 0);
}

int		is_shop(t_map *map, int id, int coin)
{
	return (((id >= FIRST_SHOP && id <= LAST_SHOP && coin >= 15) ||
			(((id == ID_HEART_SHOP && map->pick_heart < map->container * 2) 
			  || id == ID_KEY_SHOP) && coin >= 5)) ? 1 : 0);
}

int		is_door(t_map *map, int id, int x, int y)
{
	if ((id == ID_DOOR_C || id == ID_GDOOR_C) && map->pick_key)
	{
		map->board[x][y] = (id == ID_DOOR_C) ? ID_DOOR_O : ID_GDOOR_O;
		map->pick_key--;
		return (1);
	}
	else if (id == ID_DOOR_HEART && map->pick_heart >= 6)
	{
		map->board[x][y] = ID_DOOR_O;
		return (1);
	}
	return (0);
}

int		is_destroyable(t_map *map, int id)
{
	return ((id >= FIRST_SOLID && id <= LAST_SOLID && map->item_axe) ? 1 : 0);
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
	return ((is_walk(id)) ? 1 : 0);
}
