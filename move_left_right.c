/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:20:26 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 19:08:18 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_left_right(t_map *head, int i)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].x += i;
			fill_head_xy(x, y, head);
		}
		x = -1;
	}
}
