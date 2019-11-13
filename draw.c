/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/13 21:54:37 by pasosa-s         ###   ########.fr       */
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

void	pick_color(t_env *env, t_map *map, int x, int y_start)
{
	int		i;
	if (map->boo == 1)
	{
		map->d = y_start * 256 - H * 128 + map->line_height * 128;
		map->tex_y = ((map->d * TS) / map->line_height) / 256;
		i = ((map->tex_x * (env->t[map->id].bpp / 8)) +
				(map->tex_y * env->t[map->id].s_l));
		map->b = env->t[map->id].data_addr[i];
		map->g = env->t[map->id].data_addr[++i];
		map->r = env->t[map->id].data_addr[++i];
		map->color = rgb_to_int(map->r, map->g, map->b);
	}
	put_pixel(env, x, y_start, map->color);
}

void	draw_line(t_env *env, t_map *map, int x, int y_start)
{
	if (map->boo == 1)
	{
		if (map->ns_or_ew == 0)
			map->wall_x = map->pos.y + map->perp * map->ray_dir.y;
		else
			map->wall_x = map->pos.x + map->perp * map->ray_dir.x;
		map->tex_x = (int)(map->wall_x * (double)TS);
		if (map->ns_or_ew == 0 && map->ray_dir.x > 0)
			map->tex_x = TS - map->tex_x - 1;
		if (map->ns_or_ew == 1 && map->ray_dir.x < 0)
			map->tex_x = TS - map->tex_x - 1;
	}
	while (y_start <= map->y_end)
	{
		pick_color(env, env->map, x, y_start);
		y_start++;
	}
}

int		choose_color(int id, int ns_or_ew)
{
	int color;

	if (id == 0)
		color = GR;
	else if (id == 1)
		color = GG;
	else if (id == 2)
		color = GB;
	else if (id == 3)
		color = GY;
	else if (id == 4)
		color = PURPLE4;
	else if (id == 5)
		color = TUR3;
	else if (id == 6)
		color = TAMARINDO;
	else if (id == 7)
		color = PASION2;
	else if (id == 8)
		color = SGREEN;
	if (ns_or_ew == 1)
		color = color / 2;
	return (color);
}
