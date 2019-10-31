/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:55:58 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/31 21:08:44 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		place_player(t_map *map, t_complex *pos)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (map->map[y][x] == 0)
			{
				*pos = (t_complex) {.x = y, .y = x};
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
