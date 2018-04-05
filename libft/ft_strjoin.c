/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:25:32 by ybitton           #+#    #+#             */
/*   Updated: 2017/02/27 13:31:43 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*c;
	size_t		nbr;
	int			i;
	int			t;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nbr = (size_t)ft_strlen((char*)s1) + (size_t)ft_strlen((char*)s2);
	if (!(c = ft_memalloc(nbr + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	t = 0;
	while (s2[t] != '\0')
	{
		c[i] = s2[t];
		t++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
