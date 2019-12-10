/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/10 17:32:31 by pasosa-s         ###   ########.fr       */
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

void	get_quote(t_env *env, int id, t_coord c)
{
	if (id == ID_ERROR)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y, M, QUOTE1_1);
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y += 20, M, QUOTE1_2);
	}
	else if (id == ID_GUPPY)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y, M, QUOTE2_1);
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y += 20, M, QUOTE2_2);
	}
	else if (id == ID_HANGING)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y, M, QUOTE3_1);
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y += 20, M, QUOTE3_2);
	}
	else if (id >= 47 && id <= 50)
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x + 100, c.y + 400, M, PRESS);
}

void	sprite_interactions(t_env *env, int id)
{
	t_coord		c;

	c = (t_coord) {.x = W / 2 - 200, .y = H / 2 - 100};
	if (id >= FIRST_INTER && id <= LAST_INTER)
		get_quote(env, id, c);

}

void	text_gui(t_env *env, t_map *map, int **board)
{
	void	*mlx;
	void	*win;
	t_coord	c;
	int		id;

	mlx = env->mlx_ptr;
	win = env->win_ptr;
	c = (t_coord) {.x = TS - 5, .y = TS + 47};
	map->gui_str = ft_itoa(map->pick_coin);
	mlx_string_put(mlx, win, c.x, c.y, M, map->gui_str);
	ft_memdel((void **)&(map->gui_str));
	map->gui_str = ft_itoa(map->pick_key);
	mlx_string_put(mlx, win, c.x, c.y += 40, M, map->gui_str);
	ft_memdel((void **)&(map->gui_str));
	//if (env->map->item_map)
	//	text_minimap(env);
	if (board[(int)map->pos.x][(int)map->pos.y] >= FIRST_SHOP &&
			board[(int)map->pos.x][(int)map->pos.y] <= LAST_SHOP &&
			map->pick_coin < 15)
	{
		c = (t_coord) {.x = W / 2 - 100, .y = H / 2};
		mlx_string_put(mlx, win, c.x, c.y, M, "NOT ENOUGH COINS");
	}
	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	if (id >= FIRST_INTER && id <= LAST_INTER)
		sprite_interactions(env, id);
}
