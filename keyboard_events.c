/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:00:22 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/24 14:18:54 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free_board(env->map);
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	exit(EXIT_SUCCESS);
}

int		deal_key(int key, t_env *env)
{
	if (key == ESC)
		close_program(env);
	return (0);
}