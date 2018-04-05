/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:05:54 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 15:30:15 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char			*ft_strchr(const char *s, int c)
{
	char		*sss;

	sss = (char*)s;
	while (*sss)
	{
		if (*sss == c)
			return (sss);
		sss++;
	}
	if (c == '\0')
		return (sss);
	return (NULL);
}
