/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:19:20 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 19:14:33 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_xy(t_map *head, int x_len, int y_len)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	head->mlx = mlx_init();
	head->win = mlx_new_window(head->mlx, W_SIZE, W_SIZE, "mlx 42");
	while (++y < y_len)
	{
		while (++x < x_len)
			fill_head_xy(x, y, head);
		x = -1;
	}
	mlx_hook(head->win, 2, 5, my_key_funct, head);
	mlx_loop(head->mlx);
}
