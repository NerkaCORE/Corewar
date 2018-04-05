/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:25:19 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:23 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strcat(char *dest, const char *src)
{
	int			i;
	int			v;

	i = 0;
	v = 0;
	while (dest[i] != '\0')
		i++;
	while (src[v] != '\0')
	{
		dest[i] = src[v];
		v++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
