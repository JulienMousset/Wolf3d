/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:39:07 by jmousset          #+#    #+#             */
/*   Updated: 2019/11/26 21:07:37 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_walls(t_map *map)
{
	if (map->ns_or_ew == 0)
		map->perp = (map->block.x - map->pos.x +
				(1 - map->step.x) / 2) / map->ray_dir.x;
	else
		map->perp = (map->block.y - map->pos.y +
				(1 - map->step.y) / 2) / map->ray_dir.y;
	map->line_height = (int)(H / map->perp);
	map->y_start = -map->line_height / 2 + map->h2;
	(map->y_start < 0) ? map->y_start = 0 : 0;
	map->y_end = map->line_height / 2 + map->h2;
	(map->y_end >= H) ? map->y_end = H - 1 : 0;
}

void	dda(t_map *map)
{
	map->hit = 0;
	while (!map->hit)
	{
		if (map->side.x < map->side.y)
		{
			map->side.x += map->delta.x;
			map->block.x += map->step.x;
			map->ns_or_ew = 0;
		}
		else
		{
			map->side.y += map->delta.y;
			map->block.y += map->step.y;
			map->ns_or_ew = 1;
		}
		map->hit = (map->board[map->block.x][map->block.y] > 0) ? 1 : 0;
	}
}

void	set_dda_values(t_map *map)
{
	if (map->ray_dir.x < 0)
	{
		map->step.x = -1;
		map->side.x = (map->pos.x - map->block.x) * map->delta.x;
	}
	else
	{
		map->step.x = 1;
		map->side.x = (map->block.x + 1.0 - map->pos.x) * map->delta.x;
	}
	if (map->ray_dir.y < 0)
	{
		map->step.y = -1;
		map->side.y = (map->pos.y - map->block.y) * map->delta.y;
	}
	else
	{
		map->step.y = 1;
		map->side.y = (map->block.y + 1.0 - map->pos.y) * map->delta.y;
	}
}

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
		map->dist_current = H / (2.0 * y - map->h2 * 2);
		weight = (map->dist_current - map->dist_player) / (map->dist_wall - map->dist_player);
		map->current_floor.x = weight * map->floor.x + (1.0 - weight) * map->pos.x;
		map->current_floor.y = weight * map->floor.y + (1.0 - weight) * map->pos.y;
		map->floor_tex.x = (int)(map->current_floor.x * TS) % TS;
		map->floor_tex.y = (int)(map->current_floor.y * TS) % TS;

		j = ((map->floor_tex.x * (env->t[map->id].bpp / 8)) + (map->floor_tex.y * env->t[map->id].s_l));
		ft_memcpy(&map->color_str, &env->t[4].data_addr[j], sizeof(int));
		map->color = (int)map->color_str;
		map->color = (map->color >> 1) & 8355711;
		put_pixel(env, x, y, map->color);
		ft_memcpy(&map->color_str, &env->t[7].data_addr[j], sizeof(int));
		map->color = (int)map->color_str;
		map->color = (map->color >> 1) & 8355711;
		put_pixel(env, x, map->h2 * 2 - y, map->color);
		y++;
	}
	/*
	y = 0;
	while (y < map->y_start)
	{
		map->dist_current = H / (2.0 * y - map->h2 * 2);
		weight = (map->dist_current - map->dist_player) / (map->dist_wall - map->dist_player);
		map->current_floor.x = weight * map->floor.x + (1.0 - weight) * map->pos.x;
		map->current_floor.y = weight * map->floor.y + (1.0 - weight) * map->pos.y;
		map->floor_tex.x = (int)(map->current_floor.x * TS) % TS;
		map->floor_tex.y = (int)(map->current_floor.y * TS) % TS;

		j = ((map->floor_tex.x * (env->t[map->id].bpp / 8)) + (map->floor_tex.y * env->t[map->id].s_l));
		ft_memcpy(&map->color_str, &env->t[7].data_addr[j], sizeof(int));
		map->color = (int)map->color_str;
		map->color = (map->color >> 1) & 8355711;
		put_pixel(env, x, y, map->color);

		y++;
	}
	*/
}

void	ray_casting(t_env *env, t_map *map)
{
	int		x;

	x = 0;
	/*
	if (map->boo == 0)
	{
		draw_background(env);
		draw_sky(env, env->map);
	}
	*/
	draw_background(env);
	draw_sky(env, env->map);
	while (x < W)
	{
		map->camera_x = 2 * x / (double)W - 1;
		map->ray_dir.x = map->dir.x + map->plane.x * map->camera_x;
		map->ray_dir.y = map->dir.y + map->plane.y * map->camera_x;
		map->block.x = map->pos.x;
		map->block.y = map->pos.y;
		map->delta.x = fabs(1 / map->ray_dir.x);
		map->delta.y = fabs(1 / map->ray_dir.y);
		set_dda_values(map);
		dda(map);
		set_walls(map);
		map->z_buffer[x] = map->perp;
		map->id = map->board[map->block.x][map->block.y] - 1;
		draw_line(env, env->map, x, env->map->y_start);
		if (map->boo == 1)
		{
			set_floor_casting(map);
			floor_casting(env, map, x);
		}
		x++;
	}
	if (map->boo_spr == 1)
		sprites(env, env->map);
	map->mm_switch ? draw_minimap(env, env->map) : 0;
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	text_menu(env);
	map->menu ? menu(env) : 0;
}
