/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:16:10 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 18:50:48 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
}
