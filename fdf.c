/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:21:08 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/14 18:21:46 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			get_map(int x, int y, char *const *split, t_map *head)
{
	(*head).cord[y][x].z = (float)ft_atoi(split[x]);
	(*head).cord[y][x].x = x;
	(*head).cord[y][x].y = y;
	(*head).cord[y][x].color = 0x00ff00;
	return (*head);
}

void			fdf(char *s, int x, int y, int fd)
{
	char	*line;
	char	**split;
	t_map	head;

	map_create(&head, s);
	get_next_line((fd = open(s, O_RDONLY)), &line) <= 0 ? ft_error() : 0;
	(fd == -1) ? ft_error() : 0;
	head.x_len = c_count(line);
	head.x_len == 0 ? (ft_error()) : 0;
	split = ft_strsplit(line, ' ');
	while (x == -1)
	{
		while (++x < head.x_len && split[x] != NULL)
			head = get_map(x, y, split, &head);
		if (get_next_line(fd, &line))
		{
			valid(line, head);
			split = ft_strsplit(line, ' ');
			x = -1;
			y++;
		}
	}
	close(fd);
	c_ord(&head, head.x_len, (head.y_len = ++y));
}
