/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/30 19:43:26 by pasosa-s         ###   ########.fr       */
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

void		draw_line(t_env *env, int i, t_coord minMax, int color)
{
	while (minMax.x <= minMax.y)
	{
		put_pixel(env, i, minMax.x, color);
		minMax.x++;
	}
}

void		choose_color(t_map *map, int ip, int boo)
{
	int		color;

	if (ip == 1)
		color = 0xd62d20;
	else if (ip == 2)
		color = 0x008744;
	else if(ip == 3)
		color = 0x0057e7;
	if (boo == 1)
		color = color / 2;
	map->color = color;
}
