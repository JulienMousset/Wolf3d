/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:23:27 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/06 16:02:21 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	*double_loop(void *vt)
{
	int			x_start;
	int			x_end;
	int			dif;
	t_thread	*t;
	t_env		*env;
	t_map		*map;
	int			y;

	t = (t_thread *)vt;
	env = t->env;
	map = t->env->map;
	dif = map->x_end - map->x_start;
	x_start = map->x_start + dif * t->n / THREADS;
	x_end = map->x_start + dif * (t->n + 1) / THREADS;
	while (x_start < x_end)
	{
		t->tex.x = (int)(256 * (x_start - (-map->spr.width / 2 +
						map->ssx)) * TS / map->spr.width) / 256;
		if (map->transform.y > 0 && x_start > 0 && x_start < W &&
				map->transform.y < map->z_buffer[x_start])
		{
			y = map->y_start;
			while (y < map->y_end)
			{
				t->d = y - map->h2 + map->spr.height / 2;
				t->tex.y = ((t->d * TS) / map->spr.height);
				t->j = (t->tex.x * 4 + (t->tex.y * env->t[map->id].s_l));
				ft_memcpy(&t->color_str, &env->t[map->id].data_addr[t->j],
						sizeof(int));
				t->color = (int)t->color_str;
				t->color = add_smog(t->color, map->spr_dist[map->i] / 15);
				if (t->color != 0)
				{
					put_pixel(env, x_start, y, t->color);
					put_pixel(env, x_start, y, add_smog(t->color,
								abs(y - map->h2) * 0.005));
				}
				y++;
			}
		}
		x_start++;
	}
	return (0);
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
		map->i = i;
		create_threads(env, 2);
		i++;
	}
}
