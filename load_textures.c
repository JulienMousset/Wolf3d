/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:32:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/02 16:03:21 by jmousset         ###   ########.fr       */
/*   Updated: 2019/11/27 17:32:10 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_paths(char **path)
{
	path[0] = WALL;
	path[1] = FLOOR_SHOP;
	path[2] = FLOOR;
	path[3] = WALL_SECRET;
	path[4] = DOOR_CLOSED;
	path[5] = DOOR_GOLDEN_CLOSED;
	path[6] = DOOR_OPEN;
	path[7] = DOOR_GOLDEN_OPEN;
	path[8] = DOOR_SACRIFICE;
	path[9] = COIN;
	path[10] = HEART_RED;
	path[11] = HEART_RED_HALF;
	path[12] = KEY;
	path[13] = KEY_GOLDEN;
	path[14] = TREASURE_MAP;
	path[15] = HEELS;
	path[16] = POLYPHEMUS;
	path[17] = IPECAC;
	path[18] = GODHEAD;
	path[19] = COBWEB;
	path[20] = ROCK;
	path[21] = SHOPKEEPER;
}

void	load_textures(t_env *env, t_img *t, char **path)
{
	int		ts;
	int		i;

	ts = TS;
	i = 0;
	load_paths(path);
	while (i < NUM_TEX)
	{
		t[i].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, path[i], &ts, &ts);
		t[i].data_addr = mlx_get_data_addr(t[i].img_ptr, &t[i].bpp,
				&t[i].s_l, &t[i].endian);
		i++;
	}
	env->sky.img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, SKYBOX, &ts, &ts);
	env->sky.data_addr = mlx_get_data_addr(env->sky.img_ptr, &env->sky.bpp,
			&env->sky.s_l, &env->sky.endian);
	create_sprites_array(env->map);
}
