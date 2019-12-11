/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:00:33 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/15 19:36:26 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_sky(t_env *env, t_map *map)
{
	int		y_start;
	int		i;

	y_start = H - map->h2;
	i = 0;
	while (i < map->h2)
	{
		ft_memcpy(&env->data_addr[i * env->s_l],
				&env->sky.data_addr[(env->sky.bpp / 8) + ((y_start + i) * env->sky.s_l)],
				env->s_l);
		i++;
	}
}
