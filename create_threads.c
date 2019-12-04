/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:07:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/04 14:31:42 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	*draw(void *vt)
{
	int			x_start;
	int			x_end;
	t_thread	*t;
	t_env		*env;
	t_map		*map;

	t = (t_thread *)vt;
	env = t->env;
	map = t->env->map;
	x_start = W * t->n / THREADS;
	x_end = W * (t->n + 1) / THREADS;
	while (x_start < x_end)
	{
		map->camera_x = 2 * x_start / (double)W - 1;
		map->ray_dir.x = map->dir.x + map->plane.x * map->camera_x;
		map->ray_dir.y = map->dir.y + map->plane.y * map->camera_x;
		map->block.x = map->pos.x;
		map->block.y = map->pos.y;
		map->delta.x = fabs(1 / map->ray_dir.x);
		map->delta.y = fabs(1 / map->ray_dir.y);
		set_dda_values(map);
		dda(map);
		/*
		set_walls(map);
		map->z_buffer[x_start] = map->perp;
		map->id = map->board[map->block.x][map->block.y] - 1;
		//draw_line(env, env->map, x_start, env->map->y_start);
		if (map->bool_tex == 1)
		{
			set_floor_casting(map);
			floor_casting(env, map, x_start);
		}
		*/
		x_start++;
	}
	return (0);
}

void	free_t(t_thread *t)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		t[i].env = NULL;
		i++;
	}
	free(t);
	t = NULL;
}

void	create_threads(t_env *env, t_map *map)
{
	t_thread	*t;
	int			i;

	(void)map;
	draw_background(env);
	draw_sky(env, env->map);
	t = (t_thread *)malloc(sizeof(t_thread) * THREADS);
	i = 0;
	printf("lines = %d, columns = %d\n", map->nb_lines, map->nb_columns);
	while (i < THREADS)
	{
		//printf("i = %d\n", i);
		t[i].n = i;
		t[i].env = env;
		pthread_create(&t[i].t, NULL, draw, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i].t, NULL);
		i++;
	}
	//free_t(t);
	/*
	if (map->bool_spr == 1)
		sprites(env, env->map);
	map->item_map ? draw_minimap(env, env->map) : 0;
	gui(env, env->map);
	*/
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	//text_gui(env);
	//map->bool_menu ? menu(env) : 0;
}
