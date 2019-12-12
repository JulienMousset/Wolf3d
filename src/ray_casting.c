/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:45:52 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/12 19:09:43 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	set_walls(t_thread *t, t_map *map, int x_start)
{
	if (t->ns_or_ew == 0)
		t->perp = (t->block.x - map->pos.x +
				(1 - t->step.x) / 2) / t->ray_dir.x;
	else
		t->perp = (t->block.y - map->pos.y +
				(1 - t->step.y) / 2) / t->ray_dir.y;
	t->line_height = (int)(H / t->perp);
	t->y_start = -t->line_height / 2 + map->h2;
	(t->y_start < 0) ? t->y_start = 0 : 0;
	t->y_end = t->line_height / 2 + map->h2;
	(t->y_end >= H) ? t->y_end = H - 1 : 0;
	map->z_buffer[x_start] = t->perp;
	t->id = map->board[t->block.x][t->block.y] - 1;
}

void	dda(t_thread *t, t_map *map)
{
	t->hit = 0;
	while (!t->hit)
	{
		if (t->side.x < t->side.y)
		{
			t->side.x += t->delta.x;
			t->block.x += t->step.x;
			t->ns_or_ew = 0;
		}
		else
		{
			t->side.y += t->delta.y;
			t->block.y += t->step.y;
			t->ns_or_ew = 1;
		}
		t->hit = ((map->board[t->block.x][t->block.y] > 0) &&
				(map->board[t->block.x][t->block.y] < FIRST_SPR)) ? 1 : 0;
	}
}

void	set_dda_values(t_thread *t, t_map *map)
{
	if (t->ray_dir.x < 0)
	{
		t->step.x = -1;
		t->side.x = (map->pos.x - t->block.x) * t->delta.x;
	}
	else
	{
		t->step.x = 1;
		t->side.x = (t->block.x + 1.0 - map->pos.x) * t->delta.x;
	}
	if (t->ray_dir.y < 0)
	{
		t->step.y = -1;
		t->side.y = (map->pos.y - t->block.y) * t->delta.y;
	}
	else
	{
		t->step.y = 1;
		t->side.y = (t->block.y + 1.0 - map->pos.y) * t->delta.y;
	}
}

void	*ray_casting(void *vt)
{
	int			x_start;
	int			x_end;
	t_thread	*t;
	t_map		*map;

	t = (t_thread *)vt;
	map = t->env->map;
	x_start = W * t->n / THREADS;
	x_end = W * (t->n + 1) / THREADS;
	while (x_start < x_end)
	{
		t->camera_x = 2 * x_start / (double)W - 1;
		t->ray_dir.x = map->dir.x + map->plane.x * t->camera_x;
		t->ray_dir.y = map->dir.y + map->plane.y * t->camera_x;
		t->block = (t_coord) {.x = map->pos.x, .y = map->pos.y};
		t->delta.x = fabs(1 / t->ray_dir.x);
		t->delta.y = fabs(1 / t->ray_dir.y);
		set_dda_values(t, map);
		dda(t, map);
		set_walls(t, map, x_start);
		draw_line(t->env, t, x_start, t->y_start);
		map->bool_tex ? floor_casting(t->env, map, t, x_start) : 0;
		x_start++;
	}
	return (0);
}

void	image_to_window(t_env *env, t_map *map)
{
	draw_background(env);
	!map->bool_ceil ? draw_sky(env, env->map) : 0;
	create_threads(env, 1);
	if (map->bool_spr == 1)
		sprites(env, env->map);
	map->item_map ? draw_minimap(env, env->map) : 0;
	gui(env, env->map, env->map->board);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	text_gui(env, map, map->board);
	map->bool_menu ? menu(env) : 0;
	map->bool_dead = map->pick_heart == 0 ? 1 : 0;
	if (map->bool_dead)
		end_game(env, env->map);
}
