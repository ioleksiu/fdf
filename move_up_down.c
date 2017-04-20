/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:22 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 19:10:00 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_up_down(t_map *head, int i)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].y += i;
			fill_head_xy(x, y, head);
		}
		x = -1;
	}
}
