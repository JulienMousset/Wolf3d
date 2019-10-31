/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/31 12:48:27 by jmousset         ###   ########.fr       */
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

void	draw_line(t_env *env, int i, t_coord min_max, int color)
{
	while (min_max.x <= min_max.y)
	{
		put_pixel(env, i, min_max.x, color);
		min_max.x++;
	}
}

void	choose_color(t_map *map, int ip, int boo)
{
	int		color;

	if (ip == 1)
		color = 0xd62d20;
	else if (ip == 2)
		color = 0x008744;
	else if (ip == 3)
		color = 0x0057e7;
	if (boo == 1)
		color = color / 2;
	map->color = color;
}
