/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:23:52 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/15 10:41:23 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			mouse_move(int x, int y, void *param)
{
	t_env	*env;
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	env = (t_env *)param;
	if (x > W || x < 0)
		return (0);
	if (x > env->map->mouse_pos.x)
		left_or_right(KEY_D, env->map, env->map->rot_coef / 3);
	else if (x < env->map->mouse_pos.x)
		left_or_right(KEY_A, env->map, env->map->rot_coef / 3);
	env->map->mouse_pos.x = x;
	ray_casting(env, env->map);
	return (0);
}
