/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 13:58:25 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	put_pixel(t_env *env, int x, int y, int color)
{
	int		i;

	i = 0;
	if ((x >= 0 && x <= W) && (y >= 0 && y <= H))
	{
		i = ((x * (env->bpp / 8)) + (y * env->s_l));
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

int		choose_color(t_map *map, int id, int ns_or_ew)
{
	int color;

	(void)ns_or_ew;
	color = 0;
	if (id == 1 || id == 2 || id == 3 || id == 11 || id == 12 || id == 13)
		color = MARRON_3;
	else if (id == 3)
		color = DARK_BLUE;
	else if (id == 4)
		color = BOCA90;
	else if (id == 5)
		color = PINK;
	else if (id == 6)
		color = M_BROWN;
	else if (id == 7)
		color = GY;
	else if (id == 8 || id == 9)
		color = GG;
	else if (id == 10)
		color = GR;
	((id == 11 || id == 12 || id == 13) && map->item_xray) ? color = ACQUA : 0;
	if (ns_or_ew == 1)
		color = color / 2;
	return (color);
}

void	print_cardinal_walls(t_env *env, t_thread *th, int j)
{
	if (th->ns_or_ew == 0)
	{
		if (th->step.x < 0)
			ft_memcpy(&th->color_str, &env->t[0].data_addr[j], sizeof(int));
		else
			ft_memcpy(&th->color_str, &env->t[1].data_addr[j], sizeof(int));
	}
	else if (th->ns_or_ew == 1)
	{
		if (th->step.y < 0)
			ft_memcpy(&th->color_str, &env->t[2].data_addr[j], sizeof(int));
		else
			ft_memcpy(&th->color_str, &env->t[3].data_addr[j], sizeof(int));
	}
}

void	pick_color(t_env *env, t_thread *th, int x, int y_start)
{
	int		i;
	int		j;

	if (env->map->bool_tex == 1)
	{
		th->d = y_start - env->map->h2 + th->line_height / 2;
		th->tex.y = ((th->d * TS) / th->line_height);
		i = ((x * (env->bpp / 8)) + (y_start * env->s_l));
		j = ((th->tex.x * (env->t[th->id].bpp / 8)) +
				(th->tex.y * env->t[th->id].s_l));
		if (env->map->bool_card)
			print_cardinal_walls(env, th, j);
		else
			ft_memcpy(&th->color_str, &env->t[th->id].data_addr[j],
					sizeof(int));
		th->color = (int)th->color_str;
	}
	else
		th->color = choose_color(env->map, th->id + 1, th->ns_or_ew);
	th->color = darken(env, th->color, th->perp, env->map->item_candle);
	put_pixel(env, x, y_start, th->color);
	if ((th->id != ID_CDOOR - 1 || env->map->item_mantle == 0) &&
			(th->id != ID_SECRET1 - 1 || env->map->item_xray == 0))
		put_pixel(env, x, y_start, darken(env, th->color, abs(y_start -
						env->map->h2) * 0.005, env->map->item_candle));
}

void	draw_line(t_env *env, t_thread *t, int x, int y_start)
{
	if (env->map->bool_tex == 1)
	{
		if (t->ns_or_ew == 0)
			t->wall_x = env->map->pos.y + t->perp * t->ray_dir.y;
		else
			t->wall_x = env->map->pos.x + t->perp * t->ray_dir.x;
		t->wall_x -= floor((t->wall_x));
		t->tex.x = (int)(t->wall_x * (double)TS);
		if (t->ns_or_ew == 0 && t->ray_dir.x > 0)
			t->tex.x = TS - t->tex.x - 1;
		if (t->ns_or_ew == 1 && t->ray_dir.y < 0)
			t->tex.x = TS - t->tex.x - 1;
	}
	while (y_start <= t->y_end)
	{
		pick_color(env, t, x, y_start);
		y_start++;
	}
}
