/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:16:29 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/11 22:14:35 by pasosa-s         ###   ########.fr       */
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

int		ft_ishupper(int i)
{
	return (((i >= 'A' && i <= 'Q') || i == 'X') ? 1 : 0);
}

int		is_valid(char *s, int i)
{
	if (((ft_isdigit(s[i]) || ft_islower(s[i]) || ft_ishupper(s[i])) &&
				((s[i + 1] == ' ') || s[i + 1] == '\0')) ||
			((s[i] == ' ') && (ft_isdigit(s[i + 1]) || ft_islower(s[i + 1]) ||
				ft_ishupper(s[i + 1]))))
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
	if (!(check_board(map)))
	{
		ft_tabdel(map->board, map->nb_lines);
		return (0);
	}
	return (1);
}
