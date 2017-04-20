/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:14:22 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 19:22:08 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		x_transform(t_map *head, int x_len, int y_len)
{
	int		x;
	int		y;
	float	p;
	float	b;
	float	c;

	p = -1.05;
	y = -1;
	x = -1;
	while (++y < y_len)
	{
		while (++x < x_len)
		{
			b = head->cord[y][x].y;
			c = head->cord[y][x].z;
			head->cord[y][x].y = b * (float)cos(p) + c * (float)sin(p);
			head->cord[y][x].z = -(b) * (float)sin(p) + c * (float)cos(p);
		}
		x = -1;
	}
}

void		y_transform(t_map *head, int x_len, int y_len)
{
	int		x;
	int		y;
	float	p;
	float	a;
	float	c;

	p = 0.72;
	y = -1;
	x = -1;
	while (++y < y_len)
	{
		while (++x < x_len)
		{
			a = head->cord[y][x].x;
			c = head->cord[y][x].z;
			head->cord[y][x].x = a * (float)cos(p) + c * (float)sin(p);
			head->cord[y][x].z = (-a) * (float)sin(p) + c * (float)cos(p);
		}
		x = -1;
	}
}
