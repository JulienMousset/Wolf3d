/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:16:29 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/23 18:58:25 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_board(t_map *map, int **board)
{
	int		i;
	int		j;
	int		player;

	i = 0;
	player = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((i == 0 || j == 0 || i == map->nb_lines - 1
			|| j == map->nb_columns - 1) && board[i][j] == 0)
				return (0);
			if (board[i][j] == 9)
			{
				if (player > 0)
					return (0);
				else
					player++;
			}
			j++;
		}
		i++;
	}
	if (player == 0)
		return (0);
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
			printf("%d ", map->board[i][j - 1]);
		}
		printf("\n");
		i++;
		free_tmp_board(map->tmp);
		ft_memdel((void **)&(map->line));
	}
	return (1);
}

int		count_columns(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
		{
			res++;
			i++;
		}
	}
	return (res);
}

int		count_lines(t_map *map, char *file)
{
	int		read;
	int		fd;
	int		i;
	int		previous;

	i = 0;
	previous = -1;
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &map->line)))
	{
		map->nb_columns = count_columns(map->line);
		if ((previous != -1 && previous != map->nb_columns)
		|| map->nb_columns == 0)
			return (0);
		previous = map->nb_columns;
		i++;
		ft_memdel((void **)&(map->line));
	}
	if (map->nb_columns < 3 || i < 3)
		return (0);
	close(fd);
	return (i);
}

int		check_map(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		check_file(t_map *map, char *file)
{
	int			read;
	int			fd;

	if ((fd = open(file, O_DIRECTORY)) != -1
	|| (fd = open(file, O_RDONLY)) == -1)
		return (0);
	fd = open(file, O_RDONLY);
	if (!(read = get_next_line(fd, &map->line)))
		return (0);
	ft_memdel((void **)&(map->line));
	close(fd);
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &map->line)))
	{
		if (map->line[1] == '\n' || !(check_map(map->line)))
			return (0);
		ft_memdel((void **)&(map->line));
	}
	close(fd);
	return (1);
}

int		parsing(t_map *map, char *file)
{
	int		fd;

	if (!(check_file(map, file)))
		return (0);
	if (!(map->nb_lines = count_lines(map, file)))
		return (0);
	if (!(map->board = (int **)malloc(sizeof(int *) * map->nb_lines)))
		return (0);
	fd = open(file, O_RDONLY);
	fill_board(map, fd);
	close(fd);
	if (!(check_board(map, map->board)))
		return (0);
	return (1);
}
