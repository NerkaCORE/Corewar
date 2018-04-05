/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:24:22 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:11 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

intmax_t		ft_get_int(t_var *var)
{
	intmax_t	ret;

	ret = 0;
	if (var->flag & FLAG_HH)
		ret = (char)va_arg(var->ap, void *);
	else if (var->flag & FLAG_H)
		ret = (short int)va_arg(var->ap, void *);
	else if (var->flag & FLAG_L)
		ret = (long int)va_arg(var->ap, void *);
	else if (var->flag & FLAG_LL)
		ret = (long long int)va_arg(var->ap, void *);
	else if (var->flag & FLAG_J)
		ret = (intmax_t)va_arg(var->ap, void *);
	else if (var->flag & FLAG_Z)
		ret = (size_t)va_arg(var->ap, void *);
	else
		ret = (int)va_arg(var->ap, void *);
	return (ret);
}

intmax_t		ft_get_uint(t_var *var)
{
	uintmax_t	ret;

	ret = 0;
	if (var->flag & FLAG_HH)
		ret = (unsigned char)va_arg(var->ap, void *);
	else if (var->flag & FLAG_H)
		ret = (unsigned short int)va_arg(var->ap, void *);
	else if (var->flag & FLAG_L)
		ret = (unsigned long int)va_arg(var->ap, void *);
	else if (var->flag & FLAG_LL)
		ret = (unsigned long long int)va_arg(var->ap, void *);
	else if (var->flag & FLAG_J)
		ret = (uintmax_t)va_arg(var->ap, void *);
	else if (var->flag & FLAG_Z)
		ret = (size_t)va_arg(var->ap, void *);
	else
		ret = (unsigned int)va_arg(var->ap, void *);
	return (ret);
}
