/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:05:01 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 18:46:34 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*c;
	int			i;
	int			t;

	if (s != NULL)
	{
		c = (char*)ft_memalloc(len + 1);
		if (!c)
			return (NULL);
		i = start;
		t = 0;
		while (t < (int)len)
		{
			c[t] = s[i];
			i++;
			t++;
		}
		c[i] = '\0';
		return (c);
	}
	else
		return (NULL);
}
