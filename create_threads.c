/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:07:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/04 16:15:36 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	while (i < THREADS)
	{
		t[i].n = i;
		t[i].env = env;
		pthread_create(&t[i].t, NULL, ray_casting, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i].t, NULL);
		i++;
	}
	free_t(t);
	if (map->bool_spr == 1)
		sprites(env, env->map);
	map->item_map ? draw_minimap(env, env->map) : 0;
	gui(env, env->map);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	text_gui(env);
	map->bool_menu ? menu(env) : 0;
}
