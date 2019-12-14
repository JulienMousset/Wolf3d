/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:16:10 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/14 13:14:08 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	menu_text(t_env *env, int pw, int ph)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 - 30, ph + 20, M, "CONTROLS");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 100, M, "Move : [WASD] or [ARROW KEYS]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 140, M, "Strafe : [Q][E]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 180, M, "Look Up/Down : [<][>]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 220, M, "Reset Run : [SPACEBAR]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 260, M, "Open Map : [TAB]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 300, M, "Gamble : [G]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 340, M, "Run : [SHIFT]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, pw + 20, ph + 380, M, "Quit : [ESC]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 100, M, "Cardinal Mode : [C]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 140, M, "Texture Mode : [1]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 180, M, "Skybox Mode : [2]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 220, M, "Sprites Mode : [3]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 260, M, "Darkening Mode : [4]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 300, M, "Add coins/keys : [5][6]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 340, M, "Remove/Add hearts : [7][8]");
	mlx_string_put(env->mlx_ptr, env->win_ptr, W / 2 + 90, ph + 380, M, "Admin Mode : [9]");

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
			image[i] = GREY4;
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	menu_text(env, pw, ph);
}
