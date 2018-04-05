/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_resol_easy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:12:01 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:20 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

int				ft_spe_mod(t_var *var)
{
	char		*tmp;

	if (var->width)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * 2)))
			return (0);
		tmp[0] = '%';
		tmp[1] = '\0';
		tmp = ft_space(tmp, var);
		var->str = ft_strjoin_free(var->str, tmp, 2);
		return (1);
	}
	else if ((var->str = ft_strjoin_free(var->str, "%", 1)))
		return (1);
	return (0);
}

int				ft_spe_char(t_var *var)
{
	char		c;

	if (var->flag & FLAG_L)
	{
		ft_spe_wchar(var);
		return (1);
	}
	if (var->ind == 0)
		var->index = (int*)malloc(sizeof(int) * 100);
	var->free = 1;
	c = (char)va_arg(var->ap, int);
	if (c == '\0')
	{
		c = '*';
		if (!(var->flag & FLAG_NEG))
			var->index[var->ind] = ft_strlen(var->str) + var->width - 1;
		else
			var->index[var->ind] = ft_strlen(var->str);
		var->ind++;
	}
	var->str = ft_add_char(var->str, c, var);
	return (1);
}

int				ft_spe_str(t_var *var)
{
	char		*tmp;

	if (var->flag & FLAG_L)
	{
		ft_spe_wcstr(var);
		return (1);
	}
	tmp = NULL;
	if (!(tmp = (char *)va_arg(var->ap, void *)))
	{
		var->free1 = 1;
		tmp = ft_strdup("(null)");
	}
	else
		var->free = -1;
	if (var->flag & FLAG_PR)
		tmp = ft_preci_str(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 1);
	if (var->free1 == 1)
		ft_memdel((void **)&tmp);
	var->free1 = 0;
	return (1);
}

int				ft_spe_mem(t_var *var)
{
	uintmax_t	n;
	char		*tmp;

	n = (uintmax_t)va_arg(var->ap, void *);
	if (n == 0 && !(var->flag & FLAG_PR))
		tmp = ft_zero(var, 0);
	else
		tmp = to_ubase(n, 16);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (!(var->flag & FLAG_ZE) && (var->ptr = tmp))
	{
		tmp = ft_strjoin("0x", tmp);
		ft_memdel((void **)&var->ptr);
	}
	else
		var->width -= 2;
	if (var->width)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_ZE))
		tmp = ft_strjoin("0x", tmp);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int				ft_spe_l(t_var *var)
{
	var->flag |= FLAG_L;
	ft_verif_flag(var);
	if (var->form[var->i] == 'O')
		ft_spe_oct(var);
	else if (var->form[var->i] == 'U')
		ft_spe_unb(var);
	else if (var->form[var->i] == 'D')
		ft_spe_nb(var);
	return (1);
}
