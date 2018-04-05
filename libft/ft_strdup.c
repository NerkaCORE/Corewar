/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:00:30 by ybitton           #+#    #+#             */
/*   Updated: 2017/12/21 15:24:15 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft/libft.h"

char		*ft_strdup(const char *src)
{
	int		i;
	char	*dest;
	int		len;

	i = -1;
	len = ft_strlen((char *)src);
	if ((dest = (char *)malloc(sizeof(*dest) * (len + 1))) == NULL)
		return (NULL);
	while (++i < len)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
