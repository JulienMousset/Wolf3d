/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:32:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/26 16:55:34 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sprite	add_sprite(double x, double y, int i)
{
	t_sprite	new;

	new.x = x;
	new.y = y;
	new.i = i;
	return (new);
}

void	create_sprites_array(t_map *map)
{
	map->s[0] = add_sprite(5.5, 2.5, 8);
	map->s[1] = add_sprite(3.5, 3.5, 9);
	map->s[2] = add_sprite(10.5, 3.5, 8);
	map->s[3] = add_sprite(3.5, 4.5, 9);
	map->s[4] = add_sprite(2.5, 12.5, 8);
}
	
void	and_more(t_env *env, int a, int b)
{
	env->t[6].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, REDBRICK, &a, &b);
	env->t[6].data_addr = mlx_get_data_addr(env->t[6].img_ptr, &env->t[6].bpp,
			&env->t[6].s_l, &env->t[6].endian);
	env->t[7].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, WOOD, &a, &b);
	env->t[7].data_addr = mlx_get_data_addr(env->t[7].img_ptr, &env->t[7].bpp,
			&env->t[7].s_l, &env->t[7].endian);
	env->t[8].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, BARREL, &a, &b);
	env->t[8].data_addr = mlx_get_data_addr(env->t[8].img_ptr, &env->t[8].bpp,
			&env->t[8].s_l, &env->t[8].endian);
	env->t[9].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, PILLAR, &a, &b);
	env->t[9].data_addr = mlx_get_data_addr(env->t[9].img_ptr, &env->t[9].bpp,
			&env->t[9].s_l, &env->t[9].endian);
	env->sky.img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, SKYBOX, &a, &b);
	env->sky.data_addr = mlx_get_data_addr(env->sky.img_ptr, &env->sky.bpp,
			&env->sky.s_l, &env->sky.endian);
	create_sprites_array(env->map);
}

void	load_textures(t_env *env)
{
	int		a;
	int		b;

	a = TS;
	b = TS;
	env->t[0].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, BLUESTONE, &a, &b);
	env->t[0].data_addr = mlx_get_data_addr(env->t[0].img_ptr, &env->t[0].bpp,
			&env->t[0].s_l, &env->t[0].endian);
	env->t[1].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, COLORSTONE, &a, &b);
	env->t[1].data_addr = mlx_get_data_addr(env->t[1].img_ptr, &env->t[1].bpp,
			&env->t[1].s_l, &env->t[1].endian);
	env->t[2].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, EAGLE, &a, &b);
	env->t[2].data_addr = mlx_get_data_addr(env->t[2].img_ptr, &env->t[2].bpp,
			&env->t[2].s_l, &env->t[2].endian);
	env->t[3].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, GREYSTONE, &a, &b);
	env->t[3].data_addr = mlx_get_data_addr(env->t[3].img_ptr, &env->t[3].bpp,
			&env->t[3].s_l, &env->t[3].endian);
	env->t[4].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, MOSSY, &a, &b);
	env->t[4].data_addr = mlx_get_data_addr(env->t[4].img_ptr, &env->t[4].bpp,
			&env->t[4].s_l, &env->t[4].endian);
	env->t[5].img_ptr = mlx_xpm_file_to_image(env->mlx_ptr, PSTONE, &a, &b);
	env->t[5].data_addr = mlx_get_data_addr(env->t[5].img_ptr, &env->t[5].bpp,
			&env->t[5].s_l, &env->t[5].endian);
	and_more(env, a, b);
}
