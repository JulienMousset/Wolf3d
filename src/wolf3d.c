/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:21:46 by jmousset          #+#    #+#             */
/*   Updated: 2019/12/18 13:12:45 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		init_structure(t_env *env, char *file)
{
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		end(ERR_MALLOC);
	if (!ft_strcmp(file, "/dev/zero"))
		free_and_display_usage(env, ERR_DIR);
	if (!(parsing(env, file)))
		free_and_display_usage(env, ERR_USAGE);
	env->map->level = file;
	set_keys(env->map);
	set_values(env->map);
	if (!(env->map->board_cpy = board_cpy(env->map->board, env->map->nb_lines,
	env->map->nb_columns)))
		end(ERR_MALLOC);
	if (!(env->mlx_ptr = mlx_init()) ||
	!(env->win_ptr = mlx_new_window(env->mlx_ptr, W, H, "Wolf3D")) ||
	!(env->img_ptr = mlx_new_image(env->mlx_ptr, W, H)))
		free_and_display_usage(env, ERR_USAGE);
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
		end(ERR_MALLOC);
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
