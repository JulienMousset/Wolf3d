/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:17:03 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/17 16:36:13 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		randomy(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}

void	admin_mode(t_map *map)
{
	map->pick_coin = 99;
	map->pick_key = 99;
	map->container = 10;
	map->pick_heart = map->container * 2;
	map->item_map = 1;
	map->item_heels = 1;
	map->item_axe = 1;
	map->item_xray = 1;
	map->item_mantle = 1;
	map->item_candle = 5;
}

void	reset_game(t_map *map)
{
	set_values(map);
	ft_memdel((void **)&(map->s));
	ft_memdel((void **)&(map->spr_order));
	ft_memdel((void **)&(map->spr_dist));
	ft_tabdel(map->board, map->nb_lines);
	if (!(map->board = board_cpy(map->board_cpy, map->nb_lines, map->nb_columns)))
		end(ERR_MALLOC);
	create_sprites_array(map);
}

int		*array_cpy(int *src, int size)
{
	int		*dst;
	int		i;

	if (!(dst = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		**board_cpy(int **src, int nb_lines, int nb_columns)
{
	int		**dst;
	int		i;

	i = 0;
	if (!(dst = (int **)malloc(sizeof(int *) * nb_lines)))
		return (NULL);
	while (i < nb_lines)
	{
		if (!(dst[i] = array_cpy(src[i], nb_columns)))
			return (NULL);
		i++;
	}
	return (dst);
}
