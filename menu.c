/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/31 15:53:50 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	menu(t_env *env)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = env->mlx_ptr;
	win = env->win_ptr;
	x = per(W, 5);
	y = per(H, 5);
	mlx_string_put(mlx, win, x, y, M, "fps: 60");
}