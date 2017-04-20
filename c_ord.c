/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:20:10 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 18:41:58 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c_ord(t_map *head, int x_len, int y_len)
{
	x_transform(head, x_len, y_len);
	y_transform(head, x_len, y_len);
	cord_centre(head, x_len, y_len);
	print_xy(head, x_len, y_len);
}
