/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:32:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/04 19:55:00 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/11/27 17:32:10 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_paths(char **path)
{
	path[0] = WALL1;
	path[1] = WALL2;
	path[2] = WALL3;
	path[3] = WALL_SHOP;

	path[4] = DOOR_HEART;
	path[5] = DOOR_CLOSED;
	path[6] = DOOR_GOLDEN_CLOSED;

	path[7] = DOOR_OPEN;
	path[8] = DOOR_GOLDEN_OPEN;
	path[9] = DOOR_CURSE;

	path[10] = HEART_RED;
	path[11] = HEART_RED_HALF;

	path[12] = COIN;
	path[13] = KEY;

	path[14] = MAP;
	path[15] = HEELS;
	path[15] = CANDLE;

	path[15] = POLY;
	path[16] = IPECAC;
	path[17] = GODHEAD;
	path[15] = AXE;
	path[16] = MANTLE;
	path[17] = QUARTER;
	path[18] = GLASSES;
	path[19] = DINNER;
	path[20] = SHOPKEEPER;
	path[21] = CONTAINER_HEART_RED;
	path[22] = CONTAINER_HEART_RED_HALF;
	path[23] = CONTAINER_HEART_EMPTY;
	path[24] = SHIFT_ON;
	path[25] = SHIFT_OFF;
	path[26] = PRICE_TAG_15;
	path[27] = PRICE_TAG_5;
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
