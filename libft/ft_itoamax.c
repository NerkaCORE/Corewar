/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:29:38 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/01 11:30:01 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

char		*ft_itoamax(intmax_t n)
{
	char			*str;
	intmax_t		save;
	intmax_t		neg;
	intmax_t		i;

	save = n;
	neg = (n < 0 ? -1 : 1);
	i = 1 + (n < 0);
	while (n /= 10)
		i++;
	if (!(str = ft_strnew(i)))
		return (0);
	str[i--] = '\0';
	str[i--] = neg * (save % 10) + 48;
	while (save /= 10)
		str[i--] = neg * (save % 10) + 48;
	if (neg < 0)
		str[i] = '-';
	return (str);
}
