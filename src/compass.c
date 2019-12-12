/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:01:47 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/12 17:04:55 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		north(t_map *map, int x)
{
	int		color;

	color = 0;
	if (round(map->dir.x) == -1 && round(map->dir.y) == 0 &&
			(x > per(map->mm_size, 33) && x < per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.x) == -1 && round(map->dir.y) == 1 &&
			(x > per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.x) == -1 && round(map->dir.y) == -1 &&
			(x < per(map->mm_size, 33)))
		color = MARBLE;
	return (color);
}

int		south(t_map *map, int x)
{
	int		color;

	color = 0;
	if (round(map->dir.x) == 1 && round(map->dir.y) == 0 &&
			(x > per(map->mm_size, 33) && x < per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.x) == 1 && round(map->dir.y) == 1 &&
			(x > per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.x) == 1 && round(map->dir.y) == -1 &&
			(x < per(map->mm_size, 33)))
		color = MARBLE;
	return (color);
}

int		west(t_map *map, int y)
{
	int		color;

	color = 0;
	if (round(map->dir.y) == -1 && round(map->dir.x) == 0 &&
			(y > per(map->mm_size, 33) && y < per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.y) == -1 && round(map->dir.x) == 1 &&
			(y > per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.y) == -1 && round(map->dir.x) == -1 &&
			(y < per(map->mm_size, 33)))
		color = MARBLE;
	return (color);
}

int		east(t_map *map, int y)
{
	int		color;

	color = 0;
	if (round(map->dir.y) == 1 && round(map->dir.x) == 0 &&
			(y > per(map->mm_size, 33) && y < per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.y) == 1 && round(map->dir.x) == 1 &&
			(y > per(map->mm_size, 66)))
		color = MARBLE;
	if (round(map->dir.y) == 1 && round(map->dir.x) == -1 &&
			(y < per(map->mm_size, 33)))
		color = MARBLE;
	return (color);
}
