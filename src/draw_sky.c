/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:00:33 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/13 19:07:17 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	draw_simple_sky(t_env *env, t_map *map)
{
	int		y_start;
	int		i;

	y_start = H - map->h2;
	i = 0;
	while (i < map->h2)
	{
		ft_memcpy(&env->data_addr[i * env->s_l],
				&env->sky.data_addr[(env->sky.bpp / 8) + ((y_start + i) *
					env->sky.s_l)],
				env->s_l);
		i++;
	}
}

void	draw_responsive_sky(t_env *env, t_map *map)
{
	t_coord		p;
	t_coord		tex;
	int			i;
	int			j;
	int			y_start;

	y_start = H_SKY - (H_SKY / 2 + map->h2_coef / 2);
	if (y_start < 0)
		y_start = 0;
	p = (t_coord) {.x = 0, .y = 0};
	while (p.y < map->h2)
	{
		tex.y = p.y * H_SKY / H;
		p.x = 0;
		while (p.x < W)
		{
			tex.x = p.x * W_SKY / W;
			i = ((p.x * (env->bpp / 8)) + (p.y * env->s_l));
			j = ((tex.x * env->sky.bpp / 8) + (y_start + tex.y) * env->sky.s_l);
			ft_memcpy(&env->data_addr[i], &env->sky.data_addr[j], sizeof(int));
			map->color = (int)map->color_str;
			p.x++;
		}
		p.y++;
	}
}

void	draw_sky(t_env *env, t_map *map)
{
	if (W > W_SKY || H > H_SKY)
		draw_responsive_sky(env, map);
	else
		draw_simple_sky(env, map);
}
