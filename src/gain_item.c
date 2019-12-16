/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gain_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:55:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 15:09:46 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	set_limits(t_map *map, int id)
{
	if (id >= FIRST_ITEM && id <= LAST_ITEM)
		map->item_counter++;
	if (map->pick_heart > map->container * 2)
		map->pick_heart = map->container * 2;
	if (map->pick_coin > 99)
		map->pick_coin = 99;
	if (map->pick_key > 99)
		map->pick_key = 99;
}

void	buy_item_99(t_map *map, int id)
{
	if (map->pick_coin >= 99)
	{
		map->pick_coin -= 99;
		if (id == ID_POLY)
			map->item_poly = 1;
		else if (id == ID_IPECAC)
			map->item_ipecac = 1;
		else if (id == ID_GODHEAD)
			map->item_godhead = 1;
	}
}

void	buy_item(t_map *map, int id)
{
	buy_item_99(map, id);
	if (map->pick_coin >= 15)
	{
		map->pick_coin -= 15;
		if (id == ID_QUARTER)
		{
			map->pick_coin += 25;
			map->item_quarter = 1;
		}
		else if (id == ID_DINNER)
		{
			map->container++;
			map->pick_heart += 2;
			map->item_dinner = 1;
		}
		else if (id == ID_MANTLE)
			map->item_mantle = 1;
		else if (id == ID_AXE)
			map->item_axe = 1;
		else if (id == ID_XRAY)
			map->item_xray = 1;
	}
}

void	pickup_chance(t_map *map, int id)
{
	if (id == ID_ROCK1 || id == ID_ROCK2 || id == ID_ROCK3 || id == ID_POOP)
		randomy(0, 2) == 0 ? map->pick_coin++ : 0;
	else if (id == ID_SKULL)
		randomy(0, 2) == 0 ? map->pick_key++ : 0;
	else if (id == ID_URN1 || id == ID_URN2)
	{
		map->r = randomy(0, 5);
		if (map->r == 0)
			map->pick_coin++;
		else if (map->r == 2)
			map->pick_key++;
		else if (map->r == 4)
			map->pick_heart++;
	}
	else if (id == ID_MUSHROOM1 || id == ID_MUSHROOM2)
	{
		map->r = randomy(0, 5);
		if (map->r == 0)
			map->pick_coin++;
		else if (map->r == 2)
			map->pick_key++;
		else if (map->r == 4)
			map->pick_heart--;
	}
}

void	gain_item(t_map *map, int id)
{
	if (is_destroyable(map, id))
		pickup_chance(map, id);
	if (id == ID_COIN)
		map->pick_coin++;
	else if (id == ID_RHEART)
		map->pick_heart += 2;
	else if (id == ID_RHEART_HALF)
		map->pick_heart++;
	else if (id == ID_KEY)
		map->pick_key++;
	else if (id == ID_MAP)
		map->item_map = 1;
	else if (id == ID_HEELS)
		map->item_heels = 1;
	else if (id == ID_CANDLE)
		map->item_candle = 5;
	else if (id >= FIRST_SHOP && id <= LAST_SHOP)
		buy_item(map, id);
	else if ((id == ID_HEART_SHOP || id == ID_KEY_SHOP) && map->pick_coin >= 5)
	{
		map->pick_coin -= 5;
		id == ID_HEART_SHOP ? map->pick_heart += 2 : map->pick_key++;
	}
	set_limits(map, id);
}
