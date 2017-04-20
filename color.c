/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:16:43 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 18:43:31 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color(t_map *head, int color)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].color = color;
			fill_head_xy(x, y, head);
		}
		x = -1;
	}
}
