/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:42:05 by ybitton           #+#    #+#             */
/*   Updated: 2017/11/21 18:36:56 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		temp = i;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (!s2[j])
				return ((char *)&s1[temp]);
		}
		i = temp;
		i++;
	}
	return (0);
}
