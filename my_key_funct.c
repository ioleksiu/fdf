/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:18:17 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 21:52:26 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			my_key_funct(int keycode, t_map *head)
{
	mlx_clear_window(head->mlx, head->win);
	(keycode == 13 || keycode == 126) ? move_up_down(head, -1) : 0;
	(keycode == 1 || keycode == 125) ? move_up_down(head, 1) : 0;
	(keycode == 2 || keycode == 124) ? move_left_right(head, 1) : 0;
	(keycode == 0 || keycode == 123) ? move_left_right(head, -1) : 0;
	(keycode == 15) ? color(head, 0xff0000) : 0;
	(keycode == 5) ? color(head, 0x00ff00) : 0;
	(keycode == 11) ? color(head, 0x0000ff) : 0;
	(keycode == 121) ? move_up_down(head, 10) : 0;
	(keycode == 116) ? move_up_down(head, -10) : 0;
	(keycode == 119) ? move_left_right(head, 10) : 0;
	(keycode == 115) ? move_left_right(head, -10) : 0;
	(keycode == 78) ? div_xyz(head) : 0;
	(keycode == 69) ? div_mult(head) : 0;
	(keycode == 27) ? n_min(head) : 0;
	(keycode == 24) ? n_plus(head) : 0;
	if (keycode == 53)
	{
		write(1, "bye!\n", 5);
		exit(0);
	}
	return (0);
}
