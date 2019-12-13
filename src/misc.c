/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:54:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/13 15:06:23 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

unsigned int	add_smog(t_env *env, unsigned int c, double d, int candle)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (!env->map->bool_smog)
		return (c);
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

t_coord			size(t_map *map, int id, int n)
{
	t_coord		c;

	if (id == 1)
	{
		c.x = map->gui_margin.x;
		c.y = map->gui_margin.y + TS * 0.8 * n;
	}
	if (id == 2)
	{
		c.x = map->gui_margin.x;
		c.y = map->gui_margin.y;
	}
	if (id == 3)
	{
		c = (t_coord) {.x = 10, .y = per(H, 95)};
	}
	if (id == 4)
	{
		c.x = 20;
		c.y = per(H, 96);
	}
	if (id == 5)
		c = (t_coord) {.x = W / 2, .y = H - 100};
	return (c);
}

void			stop_camera(t_env *env)
{
	if (env->map->camera_h == 5)
	{
		env->map->look_up = 0;
		env->map->look_down = 0;
		env->map->camera_h = 0;
	}
	env->map->camera_h++;
	if (env->map->camera_w == 5)
	{
		env->map->mouse_left = 0;
		env->map->mouse_right = 0;
		env->map->camera_w = 0;
	}
	env->map->camera_w++;
}

void			draw_background(t_env *env)
{
	int		*image;
	int		i;

	i = 0;
	image = (int *)env->data_addr;
	i = 0;
	while (i < W * H)
	{
		if (i < W * env->map->h2)
		{
			image[i] = SKY;
		}
		else
		{
			image[i] = GROUND;
		}
		i++;
	}
}

void			bubble_sort(int *order, double *dist, int amount)
{
	int		i;
	int		j;
	int		gap;
	int		swapped;

	gap = amount;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		(gap == 9 || gap == 10) ? gap = 11 : 0;
		(gap < 1) ? gap = 1 : 0;
		swapped = 0;
		i = -1;
		while (++i < amount - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_swap_double(&dist[i], &dist[j]);
				ft_swap(&order[i], &order[j]);
				swapped = 1;
			}
		}
	}
}
