/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:32:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/29 19:35:53 by pasosa-s         ###   ########.fr       */
/*   Updated: 2019/11/27 17:32:10 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
   char	*path(int i)
   {
   char	*s;

   s = NULL;
   if (i == 0)
   s = WALL1;
   else if (i == 1)
   s = WALL2;
   else if (i == 2)
   s = FLOOR1;
   else if (i == 3)
   s = FLOOR2;
   else if (i == 4)
   s = DOOR_C;
   else if (i == 5)
   s = GDOOR_C;
   else if (i == 6)
   s = DOOR_O;
   else if (i == 7)
   s = GDOOR_O;
   else if (i == 8)
   s = CDOOR;
   else if (i == 9)
   s = KEY;
   else if (i == 10)
   s = GOLDEN;
   else if (i == 11)
   s = MAP;
   else if (i == 12)
   s = HEELS;
   else if (i == 13)
   s = COIN;
   else if (i == 14)
   s = POLY;
   return (s);
   }

   void	load_tex(t_env *env, void *mlx, int i, int ts)
   {
   env->t[i].img_ptr = mlx_xpm_file_to_image(mlx, path(i), &ts, &ts);
   env->t[i].data_addr = mlx_get_data_addr(env->t[i].img_ptr, &env->t[i].bpp,
   &env->t[i].s_l, &env->t[i].endian);
   }

   void	load_textures(t_env *env)
   {
   int		ts;
   int		i;

   ts = TS;
   i = 0;
   while (i < NUM_TEX)
   {
   load_tex(env, env->mlx_ptr, i, ts);
   i++;
   }
   env->sky.img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, SKYBOX, &ts, &ts);
   env->sky.data_addr = mlx_get_data_addr(env->sky.img_ptr, &env->sky.bpp,
   &env->sky.s_l, &env->sky.endian);
   }
   */

void	and_more(t_env *env, int ts)
{
	env->t[6].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, DOOR_O, &ts, &ts);
	env->t[6].data_addr = mlx_get_data_addr(env->t[6].img_ptr, &env->t[6].bpp,
			&env->t[6].s_l, &env->t[6].endian);
	env->t[7].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, GDOOR_O, &ts, &ts);
	env->t[7].data_addr = mlx_get_data_addr(env->t[7].img_ptr, &env->t[7].bpp,
			&env->t[7].s_l, &env->t[7].endian);
	env->t[8].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, CDOOR, &ts, &ts);
	env->t[8].data_addr = mlx_get_data_addr(env->t[8].img_ptr, &env->t[8].bpp,
			&env->t[8].s_l, &env->t[8].endian);
	env->t[9].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, KEY, &ts, &ts);
	env->t[9].data_addr = mlx_get_data_addr(env->t[9].img_ptr, &env->t[9].bpp,
			&env->t[9].s_l, &env->t[9].endian);
	env->t[10].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, GOLDEN, &ts, &ts);
	env->t[10].data_addr = mlx_get_data_addr(env->t[10].img_ptr, &env->t[10].bpp,
			&env->t[10].s_l, &env->t[10].endian);
	env->t[11].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, MAP, &ts, &ts);
	env->t[11].data_addr = mlx_get_data_addr(env->t[11].img_ptr, &env->t[11].bpp,
			&env->t[11].s_l, &env->t[11].endian);
	env->t[12].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, HEELS, &ts, &ts);
	env->t[12].data_addr = mlx_get_data_addr(env->t[12].img_ptr, &env->t[12].bpp,
			&env->t[12].s_l, &env->t[12].endian);
	env->t[13].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, COIN, &ts, &ts);
	env->t[13].data_addr = mlx_get_data_addr(env->t[13].img_ptr, &env->t[13].bpp,
			&env->t[13].s_l, &env->t[13].endian);
	env->t[14].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, POLY, &ts, &ts);
	env->t[14].data_addr = mlx_get_data_addr(env->t[14].img_ptr, &env->t[14].bpp,
			&env->t[14].s_l, &env->t[14].endian);
	env->sky.img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, SKYBOX, &ts, &ts);
	env->sky.data_addr = mlx_get_data_addr(env->sky.img_ptr, &env->sky.bpp,
			&env->sky.s_l, &env->sky.endian);
	create_sprites_array(env->map);
}

void	load_textures(t_env *env)
{
	int		ts;

	ts = TS;
	env->t[0].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, WALL1, &ts, &ts);
	env->t[0].data_addr = mlx_get_data_addr(env->t[0].img_ptr, &env->t[0].bpp,
			&env->t[0].s_l, &env->t[0].endian);
	env->t[1].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, WALL2, &ts, &ts);
	env->t[1].data_addr = mlx_get_data_addr(env->t[1].img_ptr, &env->t[1].bpp,
			&env->t[1].s_l, &env->t[1].endian);
	env->t[2].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, FLOOR1, &ts, &ts);
	env->t[2].data_addr = mlx_get_data_addr(env->t[2].img_ptr, &env->t[2].bpp,
			&env->t[2].s_l, &env->t[2].endian);
	env->t[3].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, FLOOR2, &ts, &ts);
	env->t[3].data_addr = mlx_get_data_addr(env->t[3].img_ptr, &env->t[3].bpp,
			&env->t[3].s_l, &env->t[3].endian);
	env->t[4].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, DOOR_C, &ts, &ts);
	env->t[4].data_addr = mlx_get_data_addr(env->t[4].img_ptr, &env->t[4].bpp,
			&env->t[4].s_l, &env->t[4].endian);
	env->t[5].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, GDOOR_C, &ts, &ts);
	env->t[5].data_addr = mlx_get_data_addr(env->t[5].img_ptr, &env->t[5].bpp,
			&env->t[5].s_l, &env->t[5].endian);
	and_more(env, ts);
}
