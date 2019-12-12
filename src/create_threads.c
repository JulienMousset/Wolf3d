/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:07:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/12 17:06:23 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	free_t(t_thread *t, int threads)
{
	int		i;

	i = 0;
	while (i < threads)
	{
		t[i].env = NULL;
		i++;
	}
	free(t);
	t = NULL;
}

void	create_threads(t_env *env, int id)
{
	t_thread	*t;
	int			i;
	int			threads;

	threads = (id == 1) ? THREADS : THREADS2;
	t = (t_thread *)malloc(sizeof(t_thread) * threads);
	i = 0;
	while (i < threads)
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
	while (i < threads)
	{
		pthread_join(t[i].t, NULL);
		i++;
	}
	free_t(t, threads);
}
