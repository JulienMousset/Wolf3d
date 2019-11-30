/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:22:32 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/30 20:47:44 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_floor_casting(t_map *map)
{
	if (map->ns_or_ew == 0 && map->ray_dir.x > 0)
	{
		map->floor.x = map->block.x;
		map->floor.y = map->block.y + map->wall_x;
	}
	else if (map->ns_or_ew == 0 && map->ray_dir.x < 0)
	{
		map->floor.x = map->block.x + 1.0;
		map->floor.y = map->block.y + map->wall_x;
	}
	else if (map->ns_or_ew == 1 && map->ray_dir.y > 0)
	{
		map->floor.x = map->block.x + map->wall_x;
		map->floor.y = map->block.y;
	}
	else
	{
		map->floor.x = map->block.x + map->wall_x;
		map->floor.y = map->block.y + 1.0;
	}
}

void	floor_casting(t_env *env, t_map *map, int x)
{
	int	j;
	int	y;
	double	weight;

	map->dist_wall = map->perp;
	map->dist_player = 0.0;
	if (map->y_end < 0)
		map->y_end = H;
	y = map->y_end + 1;
	while (y < H)
	{
		map->dist_current = H / (2.0 * y - map->h2 * 2.0);
		weight = (map->dist_current - map->dist_player) / (map->dist_wall - map->dist_player);
		map->current_floor.x = weight * map->floor.x + (1.0 - weight) * map->pos.x;
		map->current_floor.y = weight * map->floor.y + (1.0 - weight) * map->pos.y;
		map->floor_tex.x = (int)(map->current_floor.x * TS) % TS;
		map->floor_tex.y = (int)(map->current_floor.y * TS) % TS;

		j = ((map->floor_tex.x * (env->t[9].bpp / 8)) + (map->floor_tex.y *
					env->t[9].s_l));
		ft_memcpy(&map->color_str, &env->t[2].data_addr[j], sizeof(int));
		map->color = (int)map->color_str;
		//map->color = (map->color >> 1) & 8355711;
		put_pixel(env, x, y, map->color);
		ft_memcpy(&map->color_str, &env->t[1].data_addr[j], sizeof(int));
		map->color = (int)map->color_str;
		map->color = (map->color >> 1) & 8355711;
		put_pixel(env, x, map->h2 * 2 - y, map->color);
		y++;
	}
}

void	set_ceil_casting(t_map *map)
{
	if (map->ns_or_ew == 0 && map->ray_dir.x > 0)
	{
		map->floor.x = map->block.x;
		map->floor.y = map->block.y + map->wall_x;
	}
	else if (map->ns_or_ew == 0 && map->ray_dir.x < 0)
	{
		map->floor.x = map->block.x + 1.0;
		map->floor.y = map->block.y + map->wall_x;
	}
	else if (map->ns_or_ew == 1 && map->ray_dir.y > 0)
	{
		map->floor.x = map->block.x + map->wall_x;
		map->floor.y = map->block.y;
	}
	else
	{
		map->floor.x = map->block.x + map->wall_x;
		map->floor.y = map->block.y + 1.0;
	}
}

void	ceil_casting(t_env *env, t_map *map, int x)
{
	int	j;
	int	y;
	double	weight;

	map->dist_wall = map->perp;
	map->dist_player = 0.0;
	if (map->y_start < 0)
		map->y_start = 0;
	y = map->y_start;
	while (y > 0)
	{
		map->dist_current = H / (2.0 * y - map->h2 * 2.0);
		weight = (map->dist_current - map->dist_player) / (map->dist_wall - map->dist_player);
		map->current_floor.x = weight * map->floor.x + (1.0 - weight) * map->pos.x;
		map->current_floor.y = weight * map->floor.y + (1.0 - weight) * map->pos.y;
		map->floor_tex.x = (int)(map->current_floor.x * TS) % TS;
		map->floor_tex.y = (int)(map->current_floor.y * TS) % TS;

		j = ((map->floor_tex.x * (env->t[2].bpp / 8)) + (map->floor_tex.y *
					env->t[2].s_l));
		ft_memcpy(&map->color_str, &env->t[2].data_addr[j], sizeof(int));
		map->color = (int)map->color_str;
		map->color = (map->color >> 1) & 8355711;
		put_pixel(env, x, y, map->color);
		y--;
	}
}
