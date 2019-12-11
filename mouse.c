/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:23:52 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 17:42:15 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	mouse_move(int x, int y, t_env *env)
{
	if (env->map->bool_dead || env->map->bool_win)
		return (0);
	t_coord	coord;
	coord.x = x;
	coord.y = y;
	if (x > env->map->mouse_pos.x)
		env->map->mouse_right = 1;
	else if (x < env->map->mouse_pos.x)
		env->map->mouse_left = 1;
	/*if (y > env->map->mouse_pos.y)
		env->map->look_down = 1;
	else if (y < env->map->mouse_pos.y)
		env->map->look_up = 1;*/
	env->map->mouse_pos.x = x;
	env->map->mouse_pos.y = y;
	return (0);
}

