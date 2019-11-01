/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/01 21:44:21 by pasosa-s         ###   ########.fr       */
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

int		choose_color(int id, int ns_or_ew)
{
	int color;

	if (id == 1)
		color = GR;
	else if (id == 2)
		color = GG;
	else if (id == 3)
		color = GB;
	else if (id == 4)
		color = GY;
	else if (id == 5)
		color = PURPLE4;
	else if (id == 6)
		color = TUR3;
	else if (id == 7)
		color = TAMARINDO;
	else if (id == 8)
		color = PASION2;
	else if (id == 9)
		color = SGREEN;
	if (ns_or_ew == 1)
		color = color / 2;
	return (color);
}
