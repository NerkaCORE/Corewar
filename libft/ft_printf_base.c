/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:26:26 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:08 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

char			*to_ubase(uintmax_t n, int b)
{
	char		*s;
	char		hex[128];
	uintmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'a' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}

char			*to_ubaseup(uintmax_t n, int b)
{
	char		*s;
	char		hex[128];
	uintmax_t	t;
	int			i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 128)))
		return (NULL);
	ft_memset(s, 0, 128);
	ft_memset(hex, 0, 128);
	while (n)
	{
		t = n % b;
		if (t < 10)
			hex[i] = t + '0';
		else
			hex[i] = t + 'A' - 10;
		i++;
		n = n / b;
	}
	t = 0;
	while (i)
		s[t++] = hex[--i];
	return (s);
}
