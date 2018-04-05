/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wspe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:36:05 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:28 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

char			*wctost(wchar_t wc, t_var *var)
{
	char		tmp[5];

	if (norm_wch(var, wc, tmp) == 1)
		return (ft_strdup("NULL"));
	if (wc <= 0x7F && (var->pwc += 1))
		tmp[0] = (char)wc;
	else if (wc <= 0x7FF && (var->pwc += 2))
	{
		tmp[0] = (((wc >> 6) | 0xC0) & 0xDF);
		tmp[1] = ((wc | 0x80) & 0xBF);
	}
	else if (wc <= 0xFFFF && (var->pwc += 3))
	{
		tmp[0] = (((wc >> 12) | 0xE0) & 0xEF);
		tmp[1] = ((wc >> 6) | 0x80) & 0xBF;
		tmp[2] = ((wc | 0x80) & 0xBF);
	}
	else if (wc <= 0x10FFFF && (var->pwc += 4))
	{
		tmp[0] = (((wc >> 18) | 0xF0) & 0xF7);
		tmp[1] = (((wc >> 12) | 0x80) & 0xBF);
		tmp[2] = (((wc >> 6) | 0x80) & 0xBF);
		tmp[3] = ((wc | 0x80) & 0xBF);
	}
	return (ft_strdup(tmp));
}

int				ft_spe_wchar(t_var *var)
{
	wchar_t		wc;
	char		*tmp;
	char		*ptr;

	tmp = NULL;
	if (var->ind == 0)
		var->index = (int *)malloc(sizeof(int) * 100);
	var->free = 1;
	if (!(wc = (wchar_t)va_arg(var->ap, void *)))
	{
		if (!(tmp = ft_zero(var, 1)))
			return (0);
	}
	else
		tmp = wctost(wc, var);
	if ((var->pwc = 0) && var->width)
	{
		ptr = tmp;
		tmp = ft_space(ptr, var);
		ft_memdel((void **)&ptr);
	}
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int				ft_spe_wcstr(t_var *var)
{
	char		*tmp;
	wchar_t		*wc;

	tmp = NULL;
	wc = NULL;
	if (!(wc = (wchar_t*)va_arg(var->ap, void *)))
	{
		var->free = 1;
		tmp = ft_strjoin_free(tmp, "(null)", 1);
	}
	else if ((var->free = -1))
		tmp = norm_wcst(var, wc, tmp);
	var->pwc = 0;
	if (var->flag & FLAG_PR)
		tmp = ft_preci_str(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}
