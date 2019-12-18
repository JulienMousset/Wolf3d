/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:33 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/18 14:37:25 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	free_and_display_usage(t_env *env, char *s)
{
	if ((!ft_strcmp(ERR_NO_PLAYER, s)) || (!ft_strcmp(ERR_PLAYER, s))
		|| (!ft_strcmp(ERR_BORDER, s)))
		ft_tabdel(env->map->board, env->map->nb_lines);
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	end(s);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		end(ERR_USAGE);
	wolf3d(av[1]);
	exit(EXIT_SUCCESS);
}
