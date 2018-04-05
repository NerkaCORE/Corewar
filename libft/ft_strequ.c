/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:01:49 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 18:43:51 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

int				ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while ((unsigned char)*s1 || (unsigned char)*s2)
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
