/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:54:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/04 21:16:57 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		*ft_strint(int size)
{
	int		*str;
	int		i;

	if (!(str = (int *)malloc(sizeof(int) * size)))
		end(ERR_MALLOC);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

double	abso(double a)
{
	return ((a > 0) ? a : -a);
}

void	display_values(t_map *map)
{
	printf("map size [%d][%d]\n", map->size.x, map->size.y);
	printf("player p [%f][%f]\n", map->pos.x, map->pos.y);
	printf("player d [%f][%f]\n", map->dir.x, map->dir.y);
	printf("sign = %f\n", map->sign);
	printf("rays dir [%f][%f]\n", map->raydir.x, map->raydir.y);
	printf("block c. [%d][%d]\n", map->block.x, map->block.y);
	printf("delta xy [%f][%f]\n", map->delta.x, map->delta.y);
	printf("boo = %d\n", map->boo);
	printf("step xy  [%d][%d]\n", map->step.x, map->step.y);
	printf("side xy [%f][%f]\n", map->side.x, map->side.y);
}

