/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:23:27 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/05 15:41:37 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	double_loop(t_env *env, t_map *map, int y)
{
	int		j;

	while (map->x_start < map->x_end)
	{
		map->tex.x = (int)(256 * (map->x_start - (-map->spr.width / 2 +
						map->ssx)) * TS / map->spr.width) / 256;
		if (map->transform.y > 0 && map->x_start > 0 && map->x_start < W &&
				map->transform.y < map->z_buffer[map->x_start])
		{
			y = map->y_start;
			while (y < map->y_end)
			{
				map->d = y - map->h2 + map->spr.height / 2;
				map->tex.y = ((map->d * TS) / map->spr.height);
				j = (map->tex.x * 4 + (map->tex.y * env->t[map->id].s_l));
				ft_memcpy(&map->color_str, &env->t[map->id].data_addr[j],
						sizeof(int));
				map->color = (int)map->color_str;
				if (map->color != 0)
					put_pixel(env, map->x_start, y, map->color);
				y++;
			}
		}
		map->x_start++;
	}
}

void	set_sprite_values(t_map *map, int i)
{
	map->id = map->s[map->spr_order[i]].i;
	map->spr.x = map->s[map->spr_order[i]].x - map->pos.x;
	map->spr.y = map->s[map->spr_order[i]].y - map->pos.y;
	map->inv_det = 1.0 /
		(map->plane.x * map->dir.y - map->dir.x * map->plane.y);
	map->transform.x = map->inv_det *
		(map->dir.y * map->spr.x - map->dir.x * map->spr.y);
	map->transform.y = map->inv_det *
		(-map->plane.y * map->spr.x + map->plane.x * map->spr.y);
	map->ssx = (int)((W / 2) * (1 + map->transform.x / map->transform.y));
	map->spr.height = abs((int)(H / map->transform.y));
	map->y_start = -map->spr.height / 2 + map->h2;
	(map->y_start < 0) ? map->y_start = 0 : 0;
	map->y_end = map->spr.height / 2 + map->h2;
	(map->y_end >= H) ? map->y_end = H - 1 : 0;
	map->spr.width = abs((int)(H / map->transform.y));
	map->x_start = -map->spr.width / 2 + map->ssx;
	(map->x_start < 0) ? map->x_start = 0 : 0;
	map->x_end = map->spr.width / 2 + map->ssx;
	(map->x_end >= W) ? map->x_end = W - 1 : 0;
}

void	sprites(t_env *env, t_map *map)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < map->nb_sprites)
	{
		map->spr_order[i] = i;
		map->spr_dist[i] = (
				(map->pos.x - map->s[i].x) *
				(map->pos.x - map->s[i].x) +
				(map->pos.y - map->s[i].y) *
				(map->pos.y - map->s[i].y));
		i++;
	}
	bubble_sort(map->spr_order, map->spr_dist, map->nb_sprites);
	i = 0;
	while (i < map->nb_sprites)
	{
		set_sprite_values(map, i);
		double_loop(env, env->map, y);
		i++;
	}
}
