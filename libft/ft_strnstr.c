/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:28:20 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 16:31:05 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	nnn;
	char	*s11;
	char	*s22;

	if (!*s2)
		return ((void *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			nnn = n;
			s11 = (void *)s1 + 1;
			s22 = (void *)s2 + 1;
			while (nnn-- && *s11 && *s22 && *s11 == *s22)
			{
				++s11;
				++s22;
			}
			if (!*s22)
				return ((void *)s1);
		}
		s1++;
	}
	return (NULL);
}
