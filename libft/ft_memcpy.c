/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:54:17 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:22 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	char		*srccc;

	srccc = (char*)src;
	destination = (char*)dest;
	while (n-- > 0)
		*destination++ = *srccc++;
	return (dest);
}
