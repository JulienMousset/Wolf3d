/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:32:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/30 18:41:20 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/11/27 17:32:10 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_paths(char **path)
{
	path[0] = WALL1;
	path[1] = WALL2;
	path[2] = FLOOR1;
	path[3] = SECRET;
	path[4] = DOOR_C;
	path[5] = GDOOR_C;
	path[6] = DOOR_O;
	path[7] = GDOOR_O;
	path[8] = CDOOR;
	path[9] = COIN;
	path[10] = RHEART;
	path[11] = RHEART_HALF;
	path[12] = KEY;
	path[13] = GOLDEN;
	path[14] = MAP;
	path[15] = HEELS;
	path[16] = POLY;
	path[17] = IPECAC;
	path[18] = GODHEAD;
	path[19] = WEB;
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
