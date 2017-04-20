/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_mult_xy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:17:14 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 18:47:06 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		div_mult(t_map *head)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].y *= 1.5;
			head->cord[y][x].x *= 1.5;
			fill_head_xy(x, y, head);
		}
		x = -1;
	}
}

void		div_xyz(t_map *head)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].y /= 1.5;
			head->cord[y][x].x /= 1.5;
			fill_head_xy(x, y, head);
		}
		x = -1;
	}
}
