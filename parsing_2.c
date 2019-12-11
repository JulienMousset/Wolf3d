/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:29:31 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/11 22:14:59 by pasosa-s         ###   ########.fr       */
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
			|| j == map->nb_columns - 1) && ((map->board[i][j] == 0) ||
				map->board[i][j] > 9))
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
	int		player;

	player = 0;
	i = 0;
	while ((read = get_next_line(fd, &map->line)))
	{
		map->tmp = ft_strsplit(map->line, ' ');
		if (!(map->board[i] = (int *)malloc(sizeof(int) * map->nb_columns)))
			return (0);
		j = 0;
		while (map->tmp[j])
		{
			if (!ft_strcmp(map->tmp[j], "X"))
			{
				player++;
				if (player > 1)
					end("more than one player");
				map->board[i][j] = 0;
				map->pos_cpy = (t_complex) {.x = i + 0.1, .y = j + 0.1};
			}
			else if (ft_isdigit(map->tmp[j][0]))
				map->board[i][j] = ft_atoi(map->tmp[j]);
			else if (ft_islower(map->tmp[j][0]))
				map->board[i][j] = map->tmp[j][0] - 87;
			else if (ft_ishupper(map->tmp[j][0]))
				map->board[i][j] = map->tmp[j][0] - 29;
			j++;
		}
		i++;
		ft_arraydel(map->tmp);
		ft_memdel((void **)&(map->line));
	}
	if (player == 0)
		end("no player placed");
	return (1);
}
