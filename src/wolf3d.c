/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:46:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/14 20:11:59 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		init_structure(t_env *env, char *file)
{
	if (!(ft_strcmp(file, "/dev/zero")))
			end(ERR_DIR);
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!(parsing(env->map, file)))
		free_and_display_usage(env);
	env->map->level = file;
	set_keys(env->map);
	set_values(env->map);
	env->map->board_cpy = ft_tabcpy(env->map->board, env->map->nb_lines,
			env->map->nb_columns);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, W, H, "Wolf3D");
	env->img_ptr = mlx_new_image(env->mlx_ptr, W, H);
	env->data_addr = mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->s_l),
	&(env->endian));
	ft_bzero(env->data_addr, W * H * 4);
	load_textures(env, env->t, env->path);
	return (1);
}

int		wolf3d(char *file)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	init_structure(env, file);
	image_to_window(env, env->map);
	mlx_hook(env->win_ptr, 2, (1L << 0), key_press, env);
	mlx_hook(env->win_ptr, 3, (1L << 1), key_release, env);
	mlx_hook(env->win_ptr, 6, 0, mouse_move, env);
	mlx_loop_hook(env->mlx_ptr, multiple_events, env);
	mlx_hook(env->win_ptr, 17, 0, close_program, env);
	mlx_loop(env->mlx_ptr);
	return (1);
}
