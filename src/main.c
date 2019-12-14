/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:33 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/14 18:16:28 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	free_and_display_usage(t_env *env)
{
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	end(ERR_USAGE);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		end(ERR_USAGE);
	wolf3d(av[1]);
	exit(EXIT_SUCCESS);
}