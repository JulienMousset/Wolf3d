/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:29:31 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/28 20:41:42 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_board(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((i == 0 || j == 0 || i == map->nb_lines - 1
			|| j == map->nb_columns - 1) && (map->board[i][j] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		fill_board(t_map *map, int fd)
{
	int		read;
	int		i;
	int		j;
	int		k;

	i = 0;
	while ((read = get_next_line(fd, &map->line)))
	{
		map->tmp = ft_strsplit(map->line, ' ');
		j = 0;
		k = 0;
		if (!(map->board[i] = (int *)malloc(sizeof(int) * map->nb_columns)))
			return (0);
		while (map->tmp[j])
		{
			map->board[i][j++] = ft_atoi(map->tmp[k++]);
		}
		i++;
		free_tmp_board(map->tmp);
		ft_memdel((void **)&(map->line));
	}
	return (1);
}
