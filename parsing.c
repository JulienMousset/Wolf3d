/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:16:29 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/30 15:15:10 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		if ((previous != -1 && previous != map->nb_columns))
			return (0);
		previous = map->nb_columns;
		i++;
		ft_memdel((void **)&(map->line));
	}
	close(fd);
	return (i);
}

int		is_valid(char *s, int i)
{
	if (((ft_isdigit(s[i]) || ft_islower(s[i]) || s[i] == 'X') &&
				((s[i + 1] == ' ') || s[i + 1] == '\0')) ||
			((s[i] == ' ') &&
			 (ft_isdigit(s[i + 1]) || ft_islower(s[i + 1]) ||
			  s[i + 1] == 'X')))
		return (1);
	return (0);
}

int		check_map(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (is_valid(s, i))
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
	//ft_print_tab(map->board, map->nb_lines, map->nb_columns);
	if (!(check_board(map)))
		return (free_board(map));
	return (1);
}
