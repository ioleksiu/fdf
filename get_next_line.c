/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:20:13 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 20:41:35 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_get			*ft_list_create(int fd)
{
	t_get		*a;

	a = (t_get*)malloc(sizeof(t_get));
	a->fd = fd;
	a->rest = ft_strnew(0);
	a->next = (NULL);
	return (a);
}

void			ft_list_add(t_get *a, int fd)
{
	t_get		*b;

	b = (t_get*)malloc(sizeof(t_get));
	a->next = b;
	b->fd = fd;
	b->next = (NULL);
	b->rest = ft_strnew(1);
}

t_get			*ft_find_fd(int fd, t_get *lst)
{
	while (lst != NULL && lst->fd != fd)
		lst = lst->next;
	return (lst);
}

char			*clean_line_before_nl(t_get *lst)
{
	char		*s;
	int			len;
	char		*temp;
	char		*priva;
	char		c;

	s = lst->rest;
	if (ft_strchr(s, '\n') != NULL)
		c = '\n';
	else
		c = '\0';
	len = ft_strchr(s, c) - s;
	priva = ft_strnew(len);
	priva = ft_strncpy(priva, s, len);
	temp = ft_strchr(s, c);
	lst->rest = ++temp;
	return (priva);
}

int				get_next_line(const int fd, char **line)
{
	static t_get	*a;
	t_get			*temp;
	char			*tmp;
	ssize_t			res;

	tmp = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || (res = read(fd, NULL, 0)) < 0)
		return (-1);
	!a ? a = ft_list_create(fd) : 0;
	if (a && ft_find_fd(fd, a) == NULL)
		ft_list_add(a, fd);
	temp = ft_find_fd(fd, a);
	if (temp->rest == '\0' || ft_strchr(temp->rest, '\n') == NULL)
		while (ft_strchr(temp->rest, '\n') == NULL
	&& (res = (size_t)read(fd, tmp, BUFF_SIZE)) != 0)
			if (temp->rest != NULL)
			{
				temp->rest = ft_strjoin(temp->rest, tmp);
				ft_bzero(tmp, BUFF_SIZE);
			}
	if (!res && temp->rest[0] == '\0')
		return (0);
	*line = clean_line_before_nl(temp);
	return (1);
}
