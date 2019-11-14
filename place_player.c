/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:58 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/01 17:24:46 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		place_player(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->nb_lines)
	{
		x = 0;
		while (x < map->nb_columns)
		{
			if (map->board[y][x] == 0)
			{
				map->pos = (t_complex) {.x = y, .y = x};
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}