/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:21:21 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/13 18:53:28 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void		realloc_array(t_map *map, int x, int y, int id)
{
	t_sprite	*new;
	int			i;
	int			j;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite) * map->nb_sprites - 1)))
		end(ERR_MALLOC);
	i = 0;
	j = 0;
	while (i < map->nb_sprites)
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
	if (map->s != NULL)
		ft_memdel((void **)&(map->s));
	if (map->spr_order != NULL)
		ft_memdel((void **)&(map->spr_order));
	if (map->spr_dist != NULL)
		ft_memdel((void **)&(map->spr_dist));
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

int			nb_sprites(t_map *map)
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

void		create_sprites_array(t_map *map)
{
	int			y;
	int			x;
	int			i;

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
