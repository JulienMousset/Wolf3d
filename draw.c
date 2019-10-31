/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/31 15:49:10 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	i = 0;
	if ((x >= 0 && x <= W) && (y >= 0 && y <= H))
	{
		i = ((x * (env->bpp / 8)) + (y * env->s_l));
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

void	draw_line(t_env *env, int i)
{
	while (env->map->draw_start <= env->map->draw_end)
	{
		put_pixel(env, i, env->map->draw_start, env->map->color);
		env->map->draw_start++;
	}
}

void	choose_color(t_map *map, int ip, int ns_or_ew)
{
	if (ip == 1)
		map->color = GR;
	else if (ip == 2)
		map->color = GG;
	else if (ip == 3)
		map->color = GB;
	if (ns_or_ew == 1)
		map->color = map->color / 2;
}
