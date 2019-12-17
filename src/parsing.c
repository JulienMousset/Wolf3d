/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:13 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/17 16:16:36 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

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
		{
			ft_memdel((void **)&(map->line));
			return (0);
		}
		previous = map->nb_columns;
		i++;
		ft_memdel((void **)&(map->line));
	}
	close(fd);
	return (i);
}

int		check_map(char *s)
{
	int		i;

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

int		check_file(t_env *env, char *file)
{
	int		read;
	int		fd;

	if ((fd = open(file, O_DIRECTORY)) != -1
	|| (fd = open(file, O_RDONLY)) == -1)
		free_and_display_usage(env, ERR_DIR);
	fd = open(file, O_RDONLY);
	close(fd);
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &env->map->line)))
	{
		if (!(check_map(env->map->line)))
		{
			ft_memdel((void **)&(env->map->line));
			return (0);
		}
		ft_memdel((void **)&(env->map->line));
	}
	close(fd);
	return (1);
}

int		parsing(t_env *env, char *file)
{
	int		fd;

	if (!(check_file(env, file)))
		free_and_display_usage(env, ERR_WRONG);
	if (!(env->map->nb_lines = count_lines(env->map, file)))
		free_and_display_usage(env, ERR_LINE);
	if (!(env->map->board = (int **)malloc(sizeof(int *) * env->map->nb_lines)))
		return (0);
	fd = open(file, O_RDONLY);
	fill_board(env, fd);
	close(fd);
	if (!(check_board(env->map)))
		free_and_display_usage(env, ERR_BORDER);
	return (1);
}
