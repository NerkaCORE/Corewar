/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:15:40 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 18:41:42 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*c;
	size_t		i;

	if (s != NULL && f != NULL)
	{
		c = ft_strdup((char *)s);
		if (!c)
			return (NULL);
		i = 0;
		while (s[i])
		{
			c[i] = (*f)(c[i]);
			i++;
		}
		c[i] = '\0';
		return (c);
	}
	else
		return (NULL);
}
