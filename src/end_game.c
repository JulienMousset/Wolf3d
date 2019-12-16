/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:13:42 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/16 14:10:40 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	won_or_lost(t_env *env, t_map *map)
{
	t_coord		c;

	c = (t_coord) {.x = W / 2 - 75, .y = 0};
	if (map->bool_dead)
	{
		print_mini_sprite(env, map, ID_HANGING - 1, c);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		c = (t_coord) {.x = W / 2 - 125, .y = H / 2};
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y - 160, M, LOSE);
	}
	else if (map->bool_win)
	{
		print_mini_sprite(env, map, ID_GUPPY - 1, c);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		c = (t_coord) {.x = W / 2 - 125, .y = H / 2};
		mlx_string_put(env->mlx_ptr, env->win_ptr, c.x + 20, c.y - 160, M, WIN);
	}
}

int		final_score(t_map *map)
{
	int		score;
	int		if_win;
	int		bonus;

	if_win = 200;
	bonus = 25;
	score = map->bool_win ? if_win : 0;
	score += map->item_counter * 50;
	score += map->pick_key * 5;
	score += map->pick_coin;
	score -= (map->container * 2 - map->pick_heart) * 3;
	if (map->container * 2 == map->pick_heart)
		score += bonus;
	if (map->item_counter >= 3)
		score += bonus;
	if (score < 0)
		score = 0;
	return (score);
}

void	end_game(t_env *env, t_map *map)
{
	t_coord		c;
	char		*score;
	char		*str;

	score = ft_itoa(final_score(map));
	str = ft_strjoin("        SCORE : ", score);
	ft_bzero(env->data_addr, W * H * 4);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	won_or_lost(env, map);
	c = (t_coord) {.x = W / 2 - 125, .y = H / 2};
	mlx_string_put(env->mlx_ptr, env->win_ptr, c.x, c.y, M, str);
	mlx_string_put(env->mlx_ptr, env->win_ptr, c.x - 250, c.y + 160, M, END1);
	mlx_string_put(env->mlx_ptr, env->win_ptr, c.x + 300, c.y + 160, M, END2);
	ft_memdel((void **)&(score));
	ft_memdel((void **)&(str));
}
