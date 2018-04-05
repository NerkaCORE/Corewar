/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:21:08 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strrchr(const char *s, int c)
{
	int			i;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
