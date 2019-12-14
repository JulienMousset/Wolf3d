/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:16:10 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/14 14:27:36 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	menu_text(t_env *env, int pw, int ph)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 - 30, ph + 20, M, CON);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 100, M, CON_1);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 140, M, CON_2);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 180, M, CON_3);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 220, M, CON_4);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 260, M, CON_5);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 300, M, CON_6);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 340, M, CON_7);
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 380, M, CON_8);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 100, M, CON_9);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 140, M, CON_10);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 180, M, CON_11);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 220, M, CON_12);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 260, M, CON_13);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 300, M, CON_14);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 340, M, CON_15);
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 380, M, CON_16);
}

void	menu(t_env *env)
{
	int		*image;
	int		i;
	int		pw;
	int		ph;

	image = (int *)env->data_addr;
	i = 0;
	pw = per(W, 20);
	ph = per(H, 20);
	while (i < W * H)
	{
		if (i % W > pw && i % W < W - pw && i > W * ph && i < W * (H - ph))
			image[i] = GREY4 * i * W * H * 100000000000000000;
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	menu_text(env, pw, ph);
}
