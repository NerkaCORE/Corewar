/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:18:04 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*destination;
	const char	*srcc;
	size_t		n;
	size_t		dlennn;

	destination = dst;
	srcc = src;
	n = size;
	while (n-- != 0 && *destination != '\0')
		destination++;
	dlennn = destination - dst;
	n = size - dlennn;
	if (n == 0)
		return (dlennn + ft_strlen((char*)srcc));
	while (*srcc != '\0')
	{
		if (n != 1)
		{
			*destination++ = *srcc;
			n--;
		}
		srcc++;
	}
	*destination = '\0';
	return (dlennn + (srcc - src));
}
