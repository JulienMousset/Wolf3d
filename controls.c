/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:02:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/10/30 18:06:40 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "controls.h"

int		key_press(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == KEY_ESC)
		close_program(env);
	return (0);
}
