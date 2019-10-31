/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:32:43 by jmousset          #+#    #+#             */
/*   Updated: 2019/10/30 21:18:08 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_values(t_map *map)
{
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->time = (t_complex) {.x = 0, .y = 0};
}

int		init_structure(t_env *env, char *file)
{
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(parsing(env->map, file)))
		free_and_display_usage(env);
	set_values(env->map);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W, H, "Wolf3D");
	env->img_ptr = mlx_new_image(env->mlx_ptr, W, H);
	env->bpp = 32;
	env->s_l = W * 4;
	env->endian = 0;
	env->data_addr = mlx_get_data_addr(env->img_ptr,
			&(env->bpp), &(env->s_l), &(env->endian));
	ft_bzero(env->data_addr, W * H * 4);
	return (1);
}

int		wolf3d(char *file)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, file);
	ray_casting(env, env->map);
	mlx_hook(env->win_ptr, 2, 0, key_press, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
