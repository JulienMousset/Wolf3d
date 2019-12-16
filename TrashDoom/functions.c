/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:42:40 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/11 21:07:29 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//map->pos.x -= map->dir.x * MOVE_SPEED;

int		free_board(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_lines)
	{
		ft_memdel((void **)&(map->board[i]));
		i++;
	}
	ft_memdel((void **)&(map->board));
	return (0);
}

void	free_tmp_board(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_memdel((void **)&(s[i]));
		i++;
	}
	ft_memdel((void **)&(s));
}

int		check_map(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

void	look_left_right(t_map *map)
{
	double	angle;
	double	x_dir;

	x_dir = convert(map->old_x, -map->mouse_pos.x, map->mouse_pos.x, W);
	map->old_dir_x = x_dir;
	angle = -(x_dir * 0.7) / 10000;
	map->old_dir.x = map->dir.x;
	map->dir.x = map->dir.x * cos(angle) - map->dir.y * sin(angle);
	map->dir.y = map->old_dir.x * sin(angle) + map->dir.y * cos(angle);
	map->old_plane.x = map->plane.x;
	map->plane.x = map->plane.x * cos(angle) - map->plane.y * sin(angle);
	map->plane.y = map->old_plane.x * sin(angle) + map->plane.y * cos(angle);
}

int	mouse_move(int x, int y, t_env *env)
{
	t_coord	coord;
	coord.x = x;
	coord.y = y;
	if (x > env->map->mouse_pos.x)
		env->map->mouse_right = 1;
	else if (x < env->map->mouse_pos.x)
		env->map->mouse_left = 1;
	/*if (y > env->map->mouse_pos.y)
		env->map->look_down = 1;
	else if (y < env->map->mouse_pos.y)
		env->map->look_up = 1;*/
	env->map->mouse_pos.x = x;
	env->map->mouse_pos.y = y;
	return (0);
}

int	mouse_move(int x, int y, t_env *env)
{
	if (x != env->map->mouse_pos.x)
	{
		env->map->mouse_turn = 1;
		env->map->old_x = x;
	}
	else
		env->map->mouse_turn = 0;
	if (y > env->map->mouse_pos.y)
	{
		env->map->look_down = 1;
		env->map->look_up = 0;
	}
	else if (y < env->map->mouse_pos.y)
	{
		env->map->look_up = 1;
		env->map->look_down = 0;
	}
	//env->map->mouse_pos.x = x;
	//env->map->mouse_pos.y = y;
	return (0);
}

double	convert(int old, double min, double max, int lenght)
{
	double new;

	new = old * (max - min) / lenght + min;
	return (new);
}
