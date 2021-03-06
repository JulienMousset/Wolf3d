/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:16:47 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/12/18 12:22:50 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
