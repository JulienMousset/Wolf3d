/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:07:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/17 16:24:04 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	free_threads(t_thread *t)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		t[i].env = NULL;
		i++;
	}
	ft_memdel((void **)&(t));
}

void	create_threads(t_env *env, int id)
{
	t_thread	*t;
	int			i;

	if (!(t = (t_thread *)malloc(sizeof(t_thread) * THREADS)))
		end(ERR_MALLOC);
	i = 0;
	while (i < THREADS)
	{
		t[i].n = i;
		t[i].env = env;
		if (id == 1)
			pthread_create(&t[i].t, NULL, ray_casting, &t[i]);
		else if (id == 2)
			pthread_create(&t[i].t, NULL, horizontal_loop, &t[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(t[i].t, NULL);
		i++;
	}
	free_threads(t);
}
