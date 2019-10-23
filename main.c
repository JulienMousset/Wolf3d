/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:33 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/23 18:57:34 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
