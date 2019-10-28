/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/28 19:28:54 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_values(t_map *map)
{
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->time = (t_complex) {.x = 0, .y = 0};
	map->hit = 0;
	map->boo = 0;
}

int		init_structure(t_env *env, char *file)
{
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(parsing(env->map, file)))
		free_and_display_usage(env);
	printf("player[%f][%f]\n", env->map->pos.x, env->map->pos.y);
	set_values(env->map);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Wolf3D");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->img_data_ptr = mlx_get_data_addr(env->img_ptr, &(env->bpp),
	&(env->s_l), &(env->endian));
	return (1);
}

int		wolf3d(char *file)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, file);
	ray(env);
	mlx_hook(env->win_ptr, 2, (1L << 0), deal_key, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
