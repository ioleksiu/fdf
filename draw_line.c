/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:14:49 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 18:53:15 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		s_if(int color, t_map *head)
{
	int		i;
	int		y;
	int		x;

	head->d = (head->dy << 1) - head->dx;
	head->d1 = head->dy << 1;
	head->d2 = (head->dy - head->dx) << 1;
	mlx_pixel_put(head->mlx, head->win, head->x0, head->y0, color);
	x = head->x0 + head->sx;
	y = head->y0;
	i = 0;
	while (++i <= head->dx)
	{
		if (head->d > 0)
		{
			head->d += head->d2;
			y += head->sy;
		}
		else
			head->d += head->d1;
		mlx_pixel_put(head->mlx, head->win, x, y, color);
		x += head->sx;
	}
}

void		s_else(int color, t_map *head)
{
	int		i;
	int		y;
	int		x;

	mlx_pixel_put(head->mlx, head->win, head->x0, head->y0, color);
	head->d = (head->dx << 1) - head->dy;
	head->d1 = head->dx << 1;
	head->d2 = (head->dx - head->dy) << 1;
	y = head->y0 + head->sy;
	x = head->x0;
	i = 0;
	while (++i <= head->dy)
	{
		if (head->d > 0)
		{
			head->d += head->d2;
			x += head->sx;
		}
		else
			head->d += head->d1;
		mlx_pixel_put(head->mlx, head->win, x, y, color);
		y += head->sy;
	}
}

void		segment(int color, t_map *head)
{
	head->dx = abs(head->x1 - head->x0);
	head->dy = abs(head->y1 - head->y0);
	head->sx = head->x1 >= head->x0 ? 1 : -1;
	head->sy = head->y1 >= head->y0 ? 1 : -1;
	if (head->dy <= head->dx)
		s_if(color, head);
	else
		s_else(color, head);
}
