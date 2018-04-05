/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:18:14 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:22 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*s11;
	unsigned char		*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (n > 0 && *s11 == *s22)
	{
		s11++;
		s22++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*s11 - *s22);
}
