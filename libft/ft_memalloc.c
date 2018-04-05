/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:32:20 by ybitton           #+#    #+#             */
/*   Updated: 2017/11/21 18:40:46 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft/libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;
	char	*t;

	i = 0;
	if ((mem = (void *)malloc(size * sizeof(void))) == NULL)
		return (NULL);
	t = (char *)mem;
	if (mem != NULL)
	{
		while (i < size)
		{
			*t++ = 0;
			i++;
		}
	}
	return (mem);
}
