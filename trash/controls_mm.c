/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:11:38 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/11/15 16:14:12 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	

void	change_vis(int key, t_map *map)
{
	if (key == ARROW_RIGHT)
		map->mm_vis++;
	else
		map->mm_vis--;
	if (map->mm_vis < 0)
		map->mm_vis = 0;
}

void	change_block_size(int key, t_map *map)
{
	if (key == ARROW_UP)
		map->mm_block_size += 2;
	else
		map->mm_block_size -= 2;
	if (map->mm_block_size < 0)
		map->mm_block_size = 0;
}
