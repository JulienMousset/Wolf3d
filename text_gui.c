/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/28 20:19:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


t_cards		get_cards(t_complex dir)
{
	t_cards		c;

	c.e.str = "";
	c.w.str = "";
	c.n.str = "";
	c.s.str = "";
	if (round(dir.y) == 1)
		c.e.str = "E";
	else if (round(dir.y) == -1)
		c.w.str = "W";
	if (round(dir.x) == -1)
		c.n.str = "N";
	else if (round(dir.x) == 1)
		c.s.str = "S";
	return c;
}

void	text_minimap(t_env *env)
{
	void	*mlx;
	void	*win;
	t_cards	c;

	mlx = env->mlx_ptr;
	win = env->win_ptr;
	c = get_cards(env->map->dir);
	c.e.x = env->map->mm_end.x - 15;
	c.e.y = env->map->mm_center.y - 4;
	c.w.x = env->map->mm_start.x + 5;
	c.w.y = env->map->mm_center.y - 5;
	c.n.x = env->map->mm_center.x - 5;
	c.n.y = env->map->mm_margin.y;
	c.s.x = env->map->mm_center.x - 1;
	c.s.y = env->map->mm_margin.y + env->map->mm_size - 22;
	mlx_string_put(mlx, win, c.e.x, c.e.y, M, c.e.str);
	mlx_string_put(mlx, win, c.w.x, c.w.y, M, c.w.str);
	mlx_string_put(mlx, win, c.n.x, c.n.y, M, c.n.str);
	mlx_string_put(mlx, win, c.s.x, c.s.y, M, c.s.str);
}

void	text_gui(t_env *env)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	*str;

	mlx = env->mlx_ptr;
	win = env->win_ptr;
	x = 10;
	y = H - 30;
	str = env->map->run ? ">>" : "";

	if (env->map->bool_sprint)
	{
		mlx_string_put(mlx, win, x, y, M, "SHIFT");
		mlx_string_put(mlx, win, x += 60, y, M, str);
	}
	//mlx_string_put(mlx, win, x += 501, y, M, "map = M");
	x = TS + 30;
	y = TS + 25;
	env->map->gui_str = ft_itoa(env->map->item_key);
	mlx_string_put(mlx, win, x, y, M, "x");
	mlx_string_put(mlx, win, x += 15, y, M, env->map->gui_str);
	ft_memdel((void **)&(env->map->gui_str));
	env->map->gui_str = ft_itoa(env->map->item_golden);
	mlx_string_put(mlx, win, x -= 15, y += 64, M, "x");
	mlx_string_put(mlx, win, x += 15, y, M, env->map->gui_str);
	if (env->map->bool_mm)
		text_minimap(env);
}
