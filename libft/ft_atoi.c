/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:21:31 by ybitton           #+#    #+#             */
/*   Updated: 2017/12/21 15:18:37 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_isignored(const char c)
{
	return (c == ' ' || c == '\n' || c == '\v' || c == '\t'
			|| c == '\r' || c == '\f');
}

int			ft_atoi(const char *str)
{
	int	value;
	int	is_neg;

	value = 0;
	is_neg = 1;
	while (ft_isignored(*str))
		str++;
	if (*str == '-' || *str == '+')
		is_neg = (*str++ == '+') ? 1 : -1;
	while (ft_isdigit(*str))
		value = value * 10 + (*str++ - '0');
	return (value * is_neg);
}
