/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:38:40 by ybitton           #+#    #+#             */
/*   Updated: 2017/11/21 18:39:07 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

int					ft_strisspace(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == 0 || str[i] == 0)
		return (1);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}
