/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:33:06 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strnew(size_t size)
{
	char		*c;
	size_t		i;

	c = (char *)ft_memalloc(size + 1);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		c[i] = '\0';
		i++;
	}
	c[i] = '\0';
	return (c);
}
