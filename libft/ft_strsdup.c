/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:57:07 by ybitton           #+#    #+#             */
/*   Updated: 2017/04/04 15:57:19 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft/libft.h"

char		*ft_strsdup(const char *src, int start)
{
	int		i;
	char	*dest;
	int		len;

	i = -1;
	len = ft_strlen((char *)src);
	len = len - start;
	if ((dest = (char *)malloc(sizeof(*dest) * (len + 1))) == NULL)
		return (NULL);
	while (++i < len)
		dest[i] = src[start++];
	dest[i] = '\0';
	return (dest);
}
