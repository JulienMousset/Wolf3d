/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 17:31:01 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	add_smog(unsigned int c, double d, int candle)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	d = candle / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (r > 0)
		r = r - (r * d);
	if (g > 0)
		g = g - (g * d);
	if (b > 0)
		b = b - (b * d);
	return ((r << 16) + (g << 8) + b);
}

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

void	print_cardinal_walls(t_env *env, t_thread *th, int j)
{
	if ((th->ns_or_ew == 0 && round(env->map->dir.x) == -1) ||
			(th->ns_or_ew == 1 && round(env->map->dir.y) == -1))
		ft_memcpy(&th->color_str, &env->t[0].data_addr[j], sizeof(int));
	else if ((th->ns_or_ew == 0 && round(env->map->dir.x) == 1) ||
			(th->ns_or_ew == 0 && round(env->map->dir.y) == 1))
		ft_memcpy(&th->color_str, &env->t[1].data_addr[j], sizeof(int));
	else
		ft_memcpy(&th->color_str, &env->t[3].data_addr[j], sizeof(int));
}

/*
void	print_cardinal_walls(t_env *env, t_thread *th, int j)
{
	if ((th->ns_or_ew == 0 && round(env->map->dir.x) == -1) ||
			(th->ns_or_ew == 1 && round(env->map->dir.y) == -1))
		ft_memcpy(&th->color_str, &env->t[0].data_addr[j], sizeof(int));
	else if ((th->ns_or_ew == 0 && round(env->map->dir.x) == 1) ||
			(th->ns_or_ew == 0 && round(env->map->dir.y) == 1))
		ft_memcpy(&th->color_str, &env->t[1].data_addr[j], sizeof(int));
	else if ((th->ns_or_ew == 0 && round(env->map->dir.x) == -1) ||
			(th->ns_or_ew == 1 && round(env->map->dir.y) == -1))
		ft_memcpy(&th->color_str, &env->t[0].data_addr[j], sizeof(int));
	else if ((th->ns_or_ew == 0 && round(env->map->dir.x) == 1) ||
			(th->ns_or_ew == 0 && round(env->map->dir.y) == 1))
		ft_memcpy(&th->color_str, &env->t[1].data_addr[j], sizeof(int));
}
*/

void	pick_color(t_env *env, t_thread *th, int x, int y_start)
{
	int		i;
	int		j;
	int		d;
	if (env->map->bool_tex == 1)
	{
		d = y_start - env->map->h2 + th->line_height / 2;
		th->tex.y = ((d * TS) / th->line_height);
		i = ((x * (env->bpp / 8)) + (y_start * env->s_l));
		j = ((th->tex.x * (env->t[th->id].bpp / 8)) +
				(th->tex.y * env->t[th->id].s_l));
		if (env->map->bool_card)
			print_cardinal_walls(env, th, j);
		else
			ft_memcpy(&th->color_str, &env->t[th->id].data_addr[j], sizeof(int));
		th->color = (int)th->color_str;
	}
	else
		th->color = choose_color(th->id, th->ns_or_ew);
	th->color = add_smog(th->color, th->perp, env->map->item_candle);
	put_pixel(env, x, y_start, th->color);
	if ((th->id != ID_CDOOR - 1 || env->map->item_mantle == 0) && 
		(th->id != ID_SECRET1 - 1 || env->map->item_xray == 0))
		put_pixel(env, x, y_start, add_smog(th->color, abs(y_start - env->map->h2) * 0.005, env->map->item_candle));
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

int		choose_color(int id, int ns_or_ew)
{
	int color;

	if (id == 0)
		color = GR;
	else if (id == 1)
		color = GG;
	else if (id == 2)
		color = GB;
	else if (id == 3)
		color = GY;
	else if (id == 4)
		color = PURPLE4;
	else if (id == 5)
		color = TUR3;
	else if (id == 6)
		color = TAMARINDO;
	else if (id == 7)
		color = PASION2;
	else if (id == 8)
		color = SGREEN;
	if (ns_or_ew == 1)
		color = color / 2;
	return (color);
}
