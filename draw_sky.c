/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:00:33 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/14 19:56:51 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_sky(t_env *env, t_map *map)
{
	int		x_start;
	int		y_start;
	int		i;

	x_start = map->nb_columns + (int)map->pos.x;
	y_start = map->nb_lines + (int)map->pos.y;
	i = 0;
	while (i < H / 2)
	{
		ft_memcpy(&env->data_addr[i * env->s_l],
				&env->sky.data_addr[(x_start * (env->sky.bpp / 8)) + (i * env->sky.s_l)],
				env->s_l);
		i++;
	}
}
