/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/14 12:28:54 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		level_id(t_map *map, int id)
{
	if (!ft_strcmp(map->level, "maps/level_2"))
	{
		if (id == 1)
			return (ID_FLOOR2 - 1);
		else
			return (ID_CEILING2 - 1);
	}
	if (!ft_strcmp(map->level, "maps/level_3"))
	{
		if (id == 1)
			return (ID_FLOOR3 - 1);
		else
			return (ID_CEILING3 - 1);
	}
	else
	{
		if (id == 1)
			return (ID_FLOOR1 - 1);
		else
			return (ID_CEILING1 - 1);
	}
}

void	set_floor_casting(t_thread *t, int *y)
{
	if (t->ns_or_ew == 0 && t->ray_dir.x > 0)
	{
		t->floor.x = t->block.x;
		t->floor.y = t->block.y + t->wall_x;
	}
	else if (t->ns_or_ew == 0 && t->ray_dir.x < 0)
	{
		t->floor.x = t->block.x + 1.0;
		t->floor.y = t->block.y + t->wall_x;
	}
	else if (t->ns_or_ew == 1 && t->ray_dir.y > 0)
	{
		t->floor.x = t->block.x + t->wall_x;
		t->floor.y = t->block.y;
	}
	else
	{
		t->floor.x = t->block.x + t->wall_x;
		t->floor.y = t->block.y + 1.0;
	}
	t->dist_wall = t->perp;
	t->dist_player = 0.0;
	(t->y_end < 0) ? t->y_end = H : 0;
	*y = t->y_end - 1;
}

void	ceiling_casting(t_env *env, t_thread *t, int x, int y)
{
	if (env->map->bool_ceil)
	{
		ft_memcpy(&t->color_str, &env->t[level_id(env->map, 2)].data_addr[t->j],
				sizeof(int));
		t->color = (int)t->color_str;
		t->color = add_smog(env, t->color, t->dist_current,
				env->map->item_candle);
		put_pixel(env, x, env->map->h2 * 2 - y, t->color);
		put_pixel(env, x, env->map->h2 * 2 - y, add_smog(env, t->color,
					abs((env->map->h2 * 2 - y) - env->map->h2) * 0.005,
					env->map->item_candle));
	}
}

void	floor_casting(t_env *env, t_map *map, t_thread *t, int x)
{
	int		y;
	double	weight;

	set_floor_casting(t, &y);
	while (++y < H)
	{
		t->dist_current = H / (2.0 * y - map->h2 * 2.0);
		weight = (t->dist_current - t->dist_player) / (t->dist_wall -
				t->dist_player);
		t->current_floor.x = weight * t->floor.x + (1.0 - weight) * map->pos.x;
		t->current_floor.y = weight * t->floor.y + (1.0 - weight) * map->pos.y;
		t->floor_tex.x = (int)(t->current_floor.x * TS) % TS;
		t->floor_tex.y = (int)(t->current_floor.y * TS) % TS;
		t->j = ((t->floor_tex.x * (env->t[9].bpp / 8)) + (t->floor_tex.y *
					env->t[9].s_l));
		ft_memcpy(&t->color_str, &env->t[level_id(map, 1)].data_addr[t->j],
				sizeof(int));
		t->color = (int)t->color_str;
		t->color = add_smog(env, t->color, t->dist_current,
				env->map->item_candle);
		put_pixel(env, x, y, t->color);
		put_pixel(env, x, y, add_smog(env, t->color, abs(y - map->h2) * 0.005,
					env->map->item_candle));
		ceiling_casting(env, t, x, y + 1);
	}
}
