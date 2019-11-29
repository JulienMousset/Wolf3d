/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:19:23 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/29 19:53:27 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_mini_sprite(t_env *env, t_map *map, int id, int margin_y)
{
	t_coord		p;
	t_coord		tex;
	int			i;

	p = (t_coord) {.x = 0, .y = 0};
	while (p.y < map->gui_size)
	{
		tex.y = p.y * TS / map->gui_size;
		p.x = 0;
		while (p.x < map->gui_size)
		{
			tex.x = p.x * TS / map->gui_size;
			i = ((tex.x * env->t[8].bpp / 8) + tex.y * env->t[8].s_l);
			ft_memcpy(&map->color_str, &env->t[id].data_addr[i], sizeof(int));
			map->color = (int)map->color_str;
			if (map->color != 0)
				put_pixel(env, map->gui_margin.x + p.x, margin_y + p.y, map->color);
			p.x++;
		}
		p.y++;
	}
}
void	gui(t_env *env, t_map *map)
{
	int		size;
	int		n;

	n = map->gui_counter;
	size = map->gui_size;
	print_mini_sprite(env, map, ID_COIN - 1, map->gui_margin.y);
	print_mini_sprite(env, map, ID_KEY - 1, map->gui_margin.y + TS);
	print_mini_sprite(env, map, ID_GOLDEN - 1, map->gui_margin.y + TS * n++);
	if (map->bool_mm)
		print_mini_sprite(env, map, ID_MAP - 1, map->gui_margin.y + TS * n++);
	if (map->bool_sprint)
		print_mini_sprite(env, map, ID_HEELS - 1, map->gui_margin.y + TS * n++);
	if (map->bool_poly)
		print_mini_sprite(env, map, ID_POLY - 1, map->gui_margin.y + TS * n++);
}
