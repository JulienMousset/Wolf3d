/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:33 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/24 12:26:24 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		free_board(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_lines)
	{
		ft_memdel((void **)&(map->board[i]));
		i++;
	}
	ft_memdel((void **)&(map->board));
	return (0);
}

void	free_tmp_board(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_memdel((void **)&(s[i]));
		i++;
	}
	ft_memdel((void **)&(s));
}

void	free_and_display_usage(t_env *env)
{
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	display_usage();
}

void	display_usage(void)
{
	ft_putstr("Usage : ./wolf3d <map_file>\n");
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		wolf3d(av[1]);
	else
		display_usage();
	exit(EXIT_SUCCESS);
}
