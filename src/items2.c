/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:27:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 19:17:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		is_pickable(t_map *map, int id)
{
	return (((id >= FIRST_FREE && id <= LAST_FREE) || ((id == ID_RHEART ||
						id == ID_RHEART_HALF) &&
					map->pick_heart < map->container * 2)) ? 1 : 0);
}

int		is_walk(t_map *map, int id)
{
	return ((id == 0 || id == ID_HEART_SHOP || id == ID_KEY_SHOP ||
				(id >= FIRST_WALK && id <= LAST_WALK) ||
				(map->bool_spr == 0 && id >= FIRST_WALK)) ?
			1 : 0);
}

int		is_shop(t_map *map, int id, int coin)
{
	return (((id >= FIRST_SHOP_99 && id <= LAST_SHOP_99 && coin >= 99) ||
				(id >= FIRST_SHOP_15 && id <= LAST_SHOP_15 && coin >= 15) ||
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
