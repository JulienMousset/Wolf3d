/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:39:45 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/26 13:04:28 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	add_smog(unsigned int c, double d)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	d = 5 / (100 / d);
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

void	pick_color(t_env *env, t_map *map, int x, int y_start)
{
	int		i;
	int		j;
	char	*color_str;
	if (map->boo == 1)
	{
		map->d = y_start - map->h2 + map->line_height / 2;
		map->tex_y = ((map->d * TS) / map->line_height);
		i = ((x * (env->bpp / 8)) + (y_start * env->s_l));
		j = ((map->tex_x * (env->t[map->id].bpp / 8)) + (map->tex_y * env->t[map->id].s_l));
		ft_memcpy(&color_str, &env->t[map->id].data_addr[j], sizeof(int));
		map->color = (int)color_str;
		if (map->ns_or_ew == 1)
			map->color = (map->color >> 1) & 8355711;
	}
	else
		map->color = choose_color(map->id, map->ns_or_ew);
	map->color = add_smog(map->color, map->perp);
	put_pixel(env, x, y_start, map->color);
	put_pixel(env, x, y_start, add_smog(map->color, abs(y_start - map->h2) * 0.005));
}

void	draw_line(t_env *env, t_map *map, int x, int y_start)
{
	if (map->boo == 1)
	{
		if (map->ns_or_ew == 0)
			map->wall_x = map->pos.y + map->perp * map->ray_dir.y;
		else
			map->wall_x = map->pos.x + map->perp * map->ray_dir.x;
		map->wall_x -= floor((map->wall_x));
		map->tex_x = (int)(map->wall_x * (double)TS);
		if (map->ns_or_ew == 0 && map->ray_dir.x > 0)
			map->tex_x = TS - map->tex_x - 1;
		if (map->ns_or_ew == 1 && map->ray_dir.y < 0)
			map->tex_x = TS - map->tex_x - 1;
	}
	while (y_start <= map->y_end)
	{
		pick_color(env, env->map, x, y_start);
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
