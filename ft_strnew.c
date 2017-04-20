/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:50:35 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 21:30:09 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strnew(size_t size)
{
	char	*area;
	size_t	i;

	i = 0;
	area = (char *)malloc(size + 1);
	if (!area)
		return (NULL);
	while (i < size)
	{
		((char*)area)[i] = '\0';
		i++;
	}
	((char*)area)[i] = '\0';
	return ((char *)area);
}
