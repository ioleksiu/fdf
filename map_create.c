/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:14:00 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 22:01:58 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		map_create(t_map *head, char *av)
{
	int		fd;
	char	*line;
	int		i;
	int		len;
	int		j;

	j = -1;
	i = 0;
	fd = open(av, O_RDONLY);
	while ((len = get_next_line(fd, &line)) && len != -1)
		i++;
	if (len == -1)
		ft_error();
	len = c_count(line);
	head->cord = (t_xyz**)malloc(i * sizeof(t_xyz *));
	while (++j < i)
		head->cord[j] = (t_xyz*)malloc(len * sizeof(t_xyz));
	head->x_len = 0;
	close(fd);
}
