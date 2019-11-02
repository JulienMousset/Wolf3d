/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/02 20:35:54 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void	text_minimap(t_env *env)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	*str;
	char	*str2;

	mlx = env->mlx_ptr;
	win = env->win_ptr;
	x = W - per(W, 7) - env->map->mm_size;
	y = per(H, 25);
	str = ft_itoa(env->map->mm_block_size);
	str2 = ft_itoa(env->map->mm_vis);

	mlx_string_put(mlx, win, x, y, M, "block size:");
	mlx_string_put(mlx, win, x += 120, y, M, str);
	mlx_string_put(mlx, win, x -= 120, y += 20, M, "blocks vis:");
	mlx_string_put(mlx, win, x += 120, y, M, str2);
}

void	text_menu(t_env *env)
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
	str = env->map->run ? "on" : "off";

	mlx_string_put(mlx, win, x, y, M, "run:");
	mlx_string_put(mlx, win, x += 45, y, M, str);
	mlx_string_put(mlx, win, x += 501, y, M, "map = M");
	text_minimap(env);
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
}
