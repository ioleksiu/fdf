/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:11:11 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 20:40:17 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	a;

	a = -1;
	while (++a < len && src[a])
		dst[a] = src[a];
	a = a - 1;
	while (++a < len)
		dst[a] = '\0';
	return (dst);
}
