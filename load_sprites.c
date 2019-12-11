/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:23:25 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 15:50:10 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/12/02 16:01:21 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			in_array(t_map *map, int x, int y)
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
void		pickup_chance(t_map *map, int id)
{
	int		r;
	if (id == ID_ROCK1 || id == ID_ROCK2 || id == ID_ROCK3 || id == ID_POOP)
		randomy(0, 2) == 0 ? map->pick_coin++ : 0;
	else if (id == ID_SKULL)
		randomy(0, 2) == 0 ? map->pick_key++ : 0;
	else if (id == ID_URN1 || id ==ID_URN2)
	{
		r = randomy(0, 5);
		if (r == 0)
			map->pick_coin++;
		else if (r == 2)
			map->pick_key++;
		else if (r == 4)
			map->pick_heart++;
	}
	else if (id == ID_MUSHROOM1 || id ==ID_MUSHROOM2)
	{
		r = randomy(0, 5);
		if (r == 0)
			map->pick_coin++;
		else if (r == 2)
			map->pick_key++;
		else if (r == 4)
			map->pick_heart--;
	}
}
void		gain_item(t_map *map, int id)
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
	{
		map->pick_coin -= 15;
		if (id == ID_POLY)
			map->item_poly = 1;
		else if (id == ID_IPECAC)
			map->item_ipecac = 1;
		else if (id == ID_GODHEAD)
		{
			map->item_godhead = 1;
			map->pick_coin = 99;
			map->pick_key = 99;
		}
		else if (id == ID_QUARTER)
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
	else if ((id == ID_HEART_SHOP || id == ID_KEY_SHOP) && map->pick_coin >= 5)
	{
		map->pick_coin -= 5;
		id == ID_HEART_SHOP ? map->pick_heart += 2 : map->pick_key++;
	}
	if (map->pick_heart > map->container * 2)
		map->pick_heart = map->container * 2;
	if (map->pick_coin > 99)
		map->pick_coin = 99;
	if (map->pick_key > 99)
		map->pick_key = 99;


}

void		realloc_array(t_map *map, int x, int y, int id)
{
	t_sprite	*new;
	int			i;
	int			j;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite) * map->nb_sprites - 1)))
		end(ERR_MALLOC);
	i = 0;
	j = 0;
	while (i <  map->nb_sprites)
	{
		if (map->s[i].x == x + 0.5 && map->s[i].y == y + 0.5)
		{
			gain_item(map, id);
			map->board[x][y] = 0;
			j++;
		}
		new[i] = map->s[i + j];
		i++;
	}
	map->nb_sprites--;
	ft_memdel((void **)&(map->s));
	map->s = new;
}

void		alloc_arrays(t_map *map)
{
	if (!(map->s = (t_sprite *)malloc(sizeof(t_sprite) * map->nb_sprites)))
		end(ERR_MALLOC);
	if (!(map->spr_order = (int *)malloc(sizeof(int) * map->nb_sprites)))
		end(ERR_MALLOC);
	if (!(map->spr_dist = (double *)malloc(sizeof(double) * map->nb_sprites)))
		end(ERR_MALLOC);
}

t_sprite	add_sprite(double x, double y, int i)
{
	t_sprite	new;

	new.x = x + 0.5;
	new.y = y + 0.5;
	if (i == 51)
		new.i = 13;
	else if (i == 52)
		new.i = 16;
	else
		new.i = i - 1;
	return (new);
}

int		nb_sprites(t_map *map)
{
	int		y;
	int		x;
	int		i;

	i = 0;
	y = 0;
	while (y < map->nb_lines)
	{
		x = 0;
		while (x < map->nb_columns)
		{
			if (map->board[y][x] >= FIRST_SPR)
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	create_sprites_array(t_map *map)
{
	int			y;
	int			x;
	int			i;

	if (map->s != NULL)
		ft_memdel((void **)&(map->s));
	map->nb_sprites = nb_sprites(map);
	alloc_arrays(map);
	i = 0;
	y = 0;
	while (y < map->nb_lines)
	{
		x = 0;
		while (x < map->nb_columns)
		{
			if (map->board[y][x] >= FIRST_SPR)
			{
				map->s[i] = add_sprite(y, x, map->board[y][x]);
				i++;
			}
			x++;
		}
		y++;
	}
}

