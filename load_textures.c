/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:22:49 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 18:45:44 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_paths3(char **path)
{
	path[48] = BEGGAR_KEY;
	path[49] = DONATION_MACHINE_BLOOD;
	path[50] = CONTAINER_HEART_RED;
	path[51] = CONTAINER_HEART_RED_HALF;
	path[52] = CONTAINER_HEART_EMPTY;
	path[53] = SHIFT_ON;
	path[54] = SHIFT_OFF;
	path[55] = FLOOR1;
	path[56] = FLOOR2;
	path[57] = FLOOR3;
	path[58] = FLOOR_SHOP;
	path[59] = TAG_5;
	path[60] = TAG_15;
	path[61] = TAG_99;
	path[62] = CONTROLS;
}

void	load_paths2(char **path)
{
	path[24] = HOLY_MANTLE;
	path[25] = QUARTER;
	path[26] = XRAY_VISION;
	path[27] = DINNER;
	path[28] = COBWEB;
	path[29] = ROCK1;
	path[30] = ROCK2;
	path[31] = ROCK3;
	path[32] = URN1;
	path[33] = URN2;
	path[34] = MUSHROOM1;
	path[35] = MUSHROOM2;
	path[36] = SKULL;
	path[37] = POOP;
	path[38] = TNT;
	path[39] = CAMPFIRE;
	path[40] = DONATION_MACHINE;
	path[41] = CHEST_FINAL;
	path[42] = SHOPKEEPER;
	path[43] = ERROR;
	path[44] = GUPPY;
	path[45] = HANGING;
	path[46] = BEGGAR_COIN;
	path[47] = BEGGAR_DEVIL;
	load_paths3(path);
}

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
	path[10] = WALL1_SECRET;
	path[11] = WALL2_SECRET;
	path[12] = WALL3_SECRET;
	path[13] = HEART_RED;
	path[14] = HEART_RED_HALF;
	path[15] = COIN;
	path[16] = KEY;
	path[17] = MAP;
	path[18] = HEELS;
	path[19] = RED_CANDLE;
	path[20] = POLY;
	path[21] = IPECAC;
	path[22] = GODHEAD;
	path[23] = AXE;
	load_paths2(path);
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
