/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:54:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/06 21:45:07 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		randomy(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}

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

void	ft_tabdel(int **tab, int lines)
{
	int		i;

	i = 0;
	while (i < lines)
	{
		ft_memdel((void **)&(tab[i]));
		i++;
	}
	ft_memdel((void **)&(tab));
}

int		*ft_arraycpy(int *src, int size)
{
	int	*dst;
	int		i;

	dst = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return dst;
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
	return dst;
}

void	copy_board(t_map *map)
{
	ft_tabdel(map->board, map->nb_lines);
	map->board = ft_tabcpy(map->board_cpy, map->nb_lines, map->nb_columns);
}
