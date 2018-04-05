/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:47:42 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	int			i;

	i = 0;
	while (n > 0)
	{
		if (src[i] == '\0')
		{
			while (n > 0)
			{
				dest[i++] = 0;
				n--;
			}
			return (dest);
		}
		else
		{
			dest[i] = src[i];
			i++;
		}
		n--;
	}
	return (dest);
}
