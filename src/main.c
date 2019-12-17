/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:33 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/17 18:06:33 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	free_and_display_usage(t_env *env, char *s)
{
	if (env->map->board)
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

/*
__attribute__((destructor))
void end()
{
		while (1);
}
*/
