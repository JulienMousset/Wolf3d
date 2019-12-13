/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:23:52 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/12 17:08:32 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int	mouse_move(int x, int y, t_env *env)
{
	t_coord	coord;

	coord = (t_coord) {.x = x, .y = y};
	if (env->map->bool_dead || env->map->bool_win)
		return (0);
	if (x > env->map->mouse_pos.x)
		env->map->mouse_right = 1;
	else if (x < env->map->mouse_pos.x)
		env->map->mouse_left = 1;
	env->map->mouse_pos.x = x;
	env->map->mouse_pos.y = y;
	return (0);
}
