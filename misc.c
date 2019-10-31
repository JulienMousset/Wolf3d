/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:54:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/30 20:16:04 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "colors.h"

void	draw_background(t_env *env)
{
	int		*image;
	int		i;

	i = 0;
	image = (int *)env->data_addr;
	i = 0;
	while (i < W * H)
	{
		if (i < W * (H / 2))
		{
			image[i] = SKY;
		}
		else
		{
			image[i] = GROUND;
		}
		i++;
	}
}

int		close_program(t_env *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free_board(env->map);
	ft_memdel((void **)&(env->map));
	ft_memdel((void **)&(env));
	exit(EXIT_SUCCESS);
}

int		*ft_strint(int size)
{
	int		*str;
	int		i;

	if (!(str = (int *)malloc(sizeof(int) * size)))
		end(ERR_MALLOC);
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

double	abso(double a)
{
	return ((a > 0) ? a : -a);
}

void	display_values(t_map *map)
{
	printf("map size [%d][%d]\n", map->nb_columns, map->nb_lines);
	printf("player p [%f][%f]\n", map->pos.x, map->pos.y);
	printf("player d [%f][%f]\n", map->dir.x, map->dir.y);
	printf("sign = %f\n", map->cameraX);
	printf("rays dir [%f][%f]\n", map->rayDir.x, map->rayDir.y);
	printf("block c. [%d][%d]\n", map->block.x, map->block.y);
	printf("delta xy [%f][%f]\n", map->delta.x, map->delta.y);
	printf("boo = %d\n", map->boo);
	printf("step xy  [%d][%d]\n", map->step.x, map->step.y);
	printf("side xy [%f][%f]\n", map->side.x, map->side.y);
}

