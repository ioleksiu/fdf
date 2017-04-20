/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:20:46 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/14 16:09:25 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_color(char *s)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == ' ')
			break ;
		if (ft_strchr("0123456789abcdefABCDEF", *s))
		{
			s++;
			i++;
		}
		else
			ft_error();
		if (i > 6 || i == 0)
			ft_error();
	}
}

void		valid(char *s, t_map head)
{
	if (c_count(s) != head.x_len)
		ft_error();
	while (*s)
	{
		if (!ft_strchr("-0x123456789abcdefABCDEF ,", *s))
			ft_error();
		if (*s == ',' && *(s + 1) == '0' && *(s + 2) == 'x')
			check_color(s + 3);
		if (*s == ',' && (*(s + 1) != '0' || *(s + 2) != 'x'))
			ft_error();
		if (*s == 'x' && (*(s - 1) != '0' || *(s - 2) != ','))
			ft_error();
		s++;
	}
}
