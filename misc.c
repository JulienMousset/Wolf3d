/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:54:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/28 13:54:39 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_background(t_env *env)
{
	int		*image;
	int		i;

	i = 0;
	image = (int *)env->data_addr;
	i = 0;
	while (i < W * H)
	{
		if (i < W * env->map->h2)
		{
			image[i] = SKY;
		}
		else
		{
			image[i] = GROUND;
		}
		i++;
	}
}

int		is_walkable(t_map *map, int i, int x, int y)
{
	if (i == 9 && in_array(map, x, y))
		realloc_array(map, x, y, i);
	return ((i == 0 || i > 8 || (i > 6 && map->bool_spr == 0)) ? 1 : 0);
}

void	bubble_sort(int	*order, double *dist, int amount)
{
	int		i;
	int		j;
	int		gap;
	int		swapped;

	gap = amount;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		i = 0;
		while (i < amount - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_swap_double(&dist[i], &dist[j]);
				ft_swap(&order[i], &order[j]);
				swapped = 1;
			}
			i++;
		}
	}
}
