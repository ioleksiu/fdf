/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:17:49 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 19:24:06 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		n_min(t_map *head)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	mlx_clear_window(head->mlx, head->win);
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].y -= W_SIZE / 2;
			head->cord[y][x].x -= W_SIZE / 2;
			head->cord[y][x].y /= 1.5;
			head->cord[y][x].x /= 1.5;
			head->cord[y][x].y += W_SIZE / 2;
			head->cord[y][x].x += W_SIZE / 2;
		}
		x = -1;
	}
	color(head, head->cord[0][0].color);
}

void		n_plus(t_map *head)
{
	int		x;
	int		y;

	y = -1;
	x = -1;
	mlx_clear_window(head->mlx, head->win);
	while (++y < head->y_len)
	{
		while (++x < head->x_len)
		{
			head->cord[y][x].y -= W_SIZE / 2;
			head->cord[y][x].x -= W_SIZE / 2;
			head->cord[y][x].y *= 1.5;
			head->cord[y][x].x *= 1.5;
			head->cord[y][x].y += W_SIZE / 2;
			head->cord[y][x].x += W_SIZE / 2;
		}
		x = -1;
	}
	color(head, head->cord[0][0].color);
}
