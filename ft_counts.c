/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:04:26 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/04/13 21:29:29 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_counts(const char *s, char sp)
{
	int	i;

	i = 0;
	while (s[i] != sp && s[i] != '\0')
		i++;
	return (i);
}
