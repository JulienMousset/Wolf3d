/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/10 19:44:54 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
