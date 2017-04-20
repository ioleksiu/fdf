/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_centre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:19:47 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 18:45:16 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cord_centre(t_map *head, int x_len, int y_len)
{
	int x;
	int y;
	int mult;

	x = -1;
	y = -1;
	mult = (x_len > y_len) ? x_len : y_len;
	mult = (W_SIZE / 2) / mult;
	while (++y < y_len)
	{
		while (++x < x_len)
		{
			(head->cord[y][x].x -= x_len / 2);
			(head->cord[y][x].y -= y_len / 2);
			(head->cord[y][x].x = head->cord[y][x].x * mult + (W_SIZE / 2));
			(head->cord[y][x].y = head->cord[y][x].y * mult + (W_SIZE / 2));
		}
		x = -1;
	}
}
