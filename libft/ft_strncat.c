/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:31:06 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	char		*destination;

	destination = dest;
	while (*destination != '\0')
		destination++;
	while (n-- > 0 && *src != '\0')
		*destination++ = *src++;
	*destination = '\0';
	return (dest);
}
