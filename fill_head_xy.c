/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_head_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:18:50 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 18:54:42 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_head_xy(int x, int y, t_map *head)
{
	if (x + 1 < head->x_len)
	{
		head->x0 = (int)head->cord[y][x].x;
		head->y0 = (int)head->cord[y][x].y;
		head->x1 = (int)head->cord[y][x + 1].x;
		head->y1 = (int)head->cord[y][x + 1].y;
		segment(head->cord[y][x].color, head);
	}
	if (y + 1 < head->y_len)
	{
		head->x0 = (int)head->cord[y][x].x;
		head->y0 = (int)head->cord[y][x].y;
		head->x1 = (int)head->cord[y + 1][x].x;
		head->y1 = (int)head->cord[y + 1][x].y;
		segment(head->cord[y][x].color, head);
	}
}
