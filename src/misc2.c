/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:17:03 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/12 17:08:24 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		randomy(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
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

void	copy_board(t_map *map)
{
	ft_tabdel(map->board, map->nb_lines);
	map->board = ft_tabcpy(map->board_cpy, map->nb_lines, map->nb_columns);
}
