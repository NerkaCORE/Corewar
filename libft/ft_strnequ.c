/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:50:57 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 19:04:09 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (n-- && ((unsigned char)*s1 || (unsigned char)*s2))
		{
			if ((unsigned char)*s1 == (unsigned char)*s2)
			{
				s1++;
				s2++;
			}
			else
				return (0);
		}
		return (1);
	}
	else
		return (0);
}
