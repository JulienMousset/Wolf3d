/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:17:03 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/14 17:39:49 by pasosa-s         ###   ########.fr       */
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

int		*ft_arraycpy(int *src, int size)
{
	int		*dst;
	int		i;

	dst = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		**ft_tabcpy(int **src, int nb_lines, int nb_columns)
{
	int		**dst;
	int		i;

	i = 0;
	dst = (int **)malloc(sizeof(int *) * nb_lines);
	while (i < nb_lines)
	{
		dst[i] = ft_arraycpy(src[i], nb_columns);
		i++;
	}
	return (dst);
}

void	reset_game(t_map *map)
{
	set_values(map);
	ft_memdel((void **)&(map->s));
	ft_memdel((void **)&(map->spr_order));
	ft_memdel((void **)&(map->spr_dist));
	ft_tabdel(map->board, map->nb_lines);
	map->board = ft_tabcpy(map->board_cpy, map->nb_lines, map->nb_columns);
	create_sprites_array(map);
}
