/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/17 16:39:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	get_quote(t_env *env, int id)
{
	void	*mlx;
	t_coord	c;

	mlx = env->mlx_ptr;
	c = (t_coord) {.x = W / 2 - 100, .y = H / 2 - 125};
	if (id == ID_ERROR)
	{
		mlx_string_put(mlx, env->win_ptr, c.x - 75, c.y, M, QUOTE1_1);
		mlx_string_put(mlx, env->win_ptr, c.x - 65, c.y + 20, M, QUOTE1_2);
	}
	else if (id == ID_GUPPY)
	{
		mlx_string_put(mlx, env->win_ptr, c.x + 40, c.y, M, QUOTE2_1);
		mlx_string_put(mlx, env->win_ptr, c.x, c.y + 20, M, QUOTE2_2);
	}
	else if (id == ID_HANGING)
	{
		mlx_string_put(mlx, env->win_ptr, c.x - 100, c.y, M, QUOTE3_1);
		mlx_string_put(mlx, env->win_ptr, c.x - 40, c.y + 20, M, QUOTE3_2);
	}
	else if (id >= 47 && id <= 50)
		mlx_string_put(mlx, env->win_ptr, c.x + 20, c.y + 500, M, PRESS);
}

void	sprite_interactions(t_env *env, int id)
{
	t_coord	c;

	c = (t_coord) {.x = W / 2 - 200, .y = H / 2 - 100};
	if (id == ID_FINAL_CHEST)
	{
		env->map->bool_win = 1;
		end_game(env, env->map);
	}
	else if (id >= FIRST_INTER && id <= LAST_INTER)
		get_quote(env, id);
}

void	print_shop_message(t_env *env, t_map *map, int **board)
{
	t_coord	c;
	int		id;

	c = (t_coord) {.x = W / 2 - 100, .y = H / 2};
	id = board[(int)map->pos.x][(int)map->pos.y];
	if ((id >= FIRST_SHOP_99 && id <= LAST_SHOP_99 && map->pick_coin < 99) ||
			(id >= FIRST_SHOP_15 && id <= LAST_SHOP_15 && map->pick_coin < 15)
			|| (id >= ID_HEART_SHOP && id <= ID_KEY_SHOP && map->pick_coin < 5))
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y, M, POOR);
	else if (id == ID_HEART_SHOP && map->pick_heart == map->container * 2)
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y, M, FULL_HEALTH);
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
	if (!(map->gui_str = ft_itoa(map->pick_coin)))
		end(ERR_MALLOC);
	mlx_string_put(mlx, win, c.x, c.y, M, map->gui_str);
	ft_memdel((void **)&(map->gui_str));
	if (!(map->gui_str = ft_itoa(map->pick_key)))
		end(ERR_MALLOC);
	mlx_string_put(mlx, win, c.x, c.y += 40, M, map->gui_str);
	ft_memdel((void **)&(map->gui_str));
	mlx_string_put(mlx, win, per(W, 92), per(H, 95), M, CON_0);
	if (map->bool_spr)
		print_shop_message(env, map, board);
	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	if (id >= FIRST_INTER && id <= LAST_INTER && map->bool_spr)
		sprite_interactions(env, id);
}
