/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:17:16 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 20:49:44 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		**ft_mem_dl(void **ap)
{
	int		i;

	i = 0;
	if (ap)
	{
		while (ap[i])
			i++;
		while (ap[i])
			free(ap[i--]);
		*ap = NULL;
	}
	return (0);
}

static char		**alloc(char *s, char c)
{
	char	**dst;

	if (!(dst = (char **)malloc(sizeof(char *) * ft_countw(s, c))))
		return (0);
	if (!(dst[0] = (char*)malloc(sizeof(char) * ft_counts(s, c))))
		return (0);
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	x;
	size_t	y;

	x = 0;
	if (!s)
		return (0);
	if (!(dst = alloc((char *)s, c)))
		return (0);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			y = 0;
			if (!(dst[x] = (char*)malloc(sizeof(char) * ft_counts(s, c))))
				return (ft_mem_dl((void **)(dst)));
			while (*s != c && *s != '\0')
				dst[x][y++] = *s++;
			dst[x++][y] = '\0';
		}
	}
	dst[x] = 0;
	return (dst);
}
