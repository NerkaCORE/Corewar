/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:27:13 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:22 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	char		*srccc;

	srccc = (char*)src;
	destination = (char*)dest;
	if (srccc < destination)
	{
		srccc = srccc + n - 1;
		destination = destination + n - 1;
		while (n > 0)
		{
			*destination-- = *srccc--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*destination++ = *srccc++;
			n--;
		}
	}
	return (dest);
}
