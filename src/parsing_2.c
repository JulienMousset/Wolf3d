/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/18 13:13:09 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

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
			if ((i == 0 || j == 0 || i == map->nb_lines - 1 ||
			j == map->nb_columns - 1) && ((map->board[i][j] == 0) ||
							map->board[i][j] > 4))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_upper(int i)
{
	return (((i >= 'A' && i <= 'Q') || i == 'X') ? 1 : 0);
}

int		is_valid(char *s, int i)
{
	if (((ft_isdigit(s[i]) || ft_islower(s[i]) || is_upper(s[i])) &&
				((s[i + 1] == ' ') || s[i + 1] == '\0')) ||
			((s[i] == ' ') && (ft_isdigit(s[i + 1]) || ft_islower(s[i + 1]) ||
				is_upper(s[i + 1]))))
		return (1);
	return (0);
}

void	filling(t_map *map, int i, int *j, int *player)
{
	if (!ft_strcmp(map->tmp[*j], "X"))
	{
		(*player)++;
		if (*player > 1)
			end(ERR_PLAYER);
		map->board[i][*j] = 0;
		map->pos_cpy = (t_complex) {.x = i + 0.1, .y = *j + 0.1};
	}
	else if (ft_isdigit(map->tmp[*j][0]))
		map->board[i][*j] = ft_atoi(map->tmp[*j]);
	else if (ft_islower(map->tmp[*j][0]))
		map->board[i][*j] = map->tmp[*j][0] - 87;
	else if (is_upper(map->tmp[*j][0]))
		map->board[i][*j] = map->tmp[*j][0] - 29;
	(*j)++;
}

int		fill_board(t_env *env, int fd)
{
	int		read;
	int		i;
	int		j;
	int		player;

	player = 0;
	i = 0;
	while ((read = get_next_line(fd, &env->map->line)))
	{
		env->map->tmp = ft_strsplit(env->map->line, ' ');
		if (!(env->map->board[i] = (int *)malloc(sizeof(int) *
		env->map->nb_columns)))
			return (0);
		j = 0;
		while (env->map->tmp[j])
			filling(env->map, i, &j, &player);
		i++;
		ft_arraydel(env->map->tmp);
		ft_memdel((void **)&(env->map->line));
	}
	if (player == 0)
		free_and_display_usage(env, ERR_NO_PLAYER);
	return (1);
}
