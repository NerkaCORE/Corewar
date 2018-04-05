/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:47:47 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 18:42:25 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		c = ft_strdup((char *)s);
		if (!c)
			return (NULL);
		i = 0;
		while (s[i])
		{
			c[i] = (*f)(i, c[i]);
			i++;
		}
		c[i] = '\0';
		return (c);
	}
	else
		return (NULL);
}
