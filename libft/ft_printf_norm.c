/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:56:04 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:15 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

void		norm_sp(t_var *var)
{
	if (var->flag & FLAG_SP)
		var->width--;
	if ((var->flag & FLAG_DI) && (var->flag & FLAG_ZE) && var->spe == 'x')
		var->width -= 2;
	else if (((var->flag & FLAG_ZE) && (var->flag & FLAG_POS)) ||
			((var->flag & FLAG_ZE) && var->neg == 1))
		var->width--;
}

int			norm_wch(t_var *var, wchar_t wc, char *tmp)
{
	ft_bzero(tmp, 5);
	if ((wc < 0 || (wc > 55295 && wc < 57344) || wc > 1114111)
			&& (var->naze = -1))
		return (1);
	return (0);
}

char		*norm_wcst(t_var *var, wchar_t *wc, char *tmp)
{
	char	*ptr;

	while (*wc)
	{
		ptr = wctost(*wc, var);
		if ((var->preci) && (var->pwc > var->preci + 1))
		{
			ft_memdel((void **)&ptr);
			break ;
		}
		tmp = ft_strjoin_free(tmp, ptr, 1);
		ft_memdel((void **)&ptr);
		if (*wc++)
			;
	}
	return (tmp);
}

char		*ft_zero(t_var *var, int x)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * (2))))
		return (NULL);
	if (x == 0)
		tmp[0] = '0';
	else
		tmp[0] = '*';
	tmp[1] = '\0';
	if (x == 1)
	{
		var->index[var->ind] = ft_strlen(var->str) + var->width - 1;
		var->ind++;
	}
	return (tmp);
}
