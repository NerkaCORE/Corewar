/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:06:48 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:22 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*destination;
	char		*srccc;

	srccc = (char*)src;
	destination = (char*)dest;
	while (n > 0 && *srccc != c)
	{
		n--;
		*destination++ = *srccc++;
	}
	if (n > 0)
	{
		*destination++ = *srccc++;
		return ((void*)destination);
	}
	else
		return (NULL);
}
