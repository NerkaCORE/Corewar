/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_resol_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:22:55 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:56:57 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

int					ft_spe_nb(t_var *var)
{
	intmax_t		n;
	char			*tmp;

	n = ft_get_int(var);
	if (n < 0 && (var->neg = 1))
		n = -n;
	if ((tmp = ft_itoamax(n)) && (var->flag & FLAG_PR))
		tmp = ft_preci_nb(tmp, var);
	if (var->neg == 1 && !(var->flag & FLAG_ZE) && (n + 1 != MAX))
		tmp = ft_strjoin_free("-", tmp, 3);
	if ((var->flag & FLAG_POS) && n >= 0 && var->neg == 0 &&
			!(var->flag & FLAG_ZE))
		tmp = ft_strjoin_free("+", tmp, 3);
	if (var->width)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_POS) && var->neg == 0 && (var->flag & FLAG_ZE))
		tmp = ft_strjoin_free("+", tmp, 3);
	if (var->neg == 1 && (var->flag & FLAG_ZE) && (n + 1 != MAX))
		tmp = ft_strjoin_free("-", tmp, 3);
	if ((var->flag & FLAG_SP) && n >= 0 && var->neg == 0)
		tmp = ft_strjoin_free(" ", tmp, 3);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	var->neg = 0;
	return (1);
}

int					ft_spe_unb(t_var *var)
{
	uintmax_t		n;
	char			*tmp;

	n = ft_get_uint(var);
	if (n == 0 && !(var->flag & FLAG_PR))
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	else
		tmp = to_ubase(n, 10);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int					ft_spe_oct(t_var *var)
{
	uintmax_t		n;
	char			*tmp;

	var->spe = 'o';
	n = ft_get_uint(var);
	if (n == 0 && ((!(var->preci) && !(var->flag & FLAG_PR)) ||
				(var->flag & FLAG_DI)))
	{
		if (!(tmp = malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	else
		tmp = to_ubase(n, 8);
	if ((var->flag & FLAG_DI) && n != 0)
		tmp = ft_strjoin("0", tmp);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int					ft_spe_hex(t_var *var)
{
	uintmax_t		n;
	char			*tmp;

	tmp = NULL;
	n = ft_get_uint(var);
	if (n == 0 && !(var->flag & FLAG_PR))
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (2))))
			return (0);
		tmp[0] = '0';
		tmp[1] = '\0';
	}
	else
		tmp = to_ubase(n, 16);
	if ((var->spe = 'x') && var->preci)
		tmp = ft_preci_nb(tmp, var);
	if ((var->flag & FLAG_DI) && !(var->flag & FLAG_ZE) && n != 0)
		tmp = ft_strjoin_free("0x", tmp, 3);
	if (var->width > 0)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_DI) && (var->flag & FLAG_ZE) && n != 0)
		tmp = ft_strjoin_free("0x", tmp, 3);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int					ft_spe_hexup(t_var *var)
{
	uintmax_t		n;
	char			*tmp;

	var->spe = 'x';
	n = ft_get_uint(var);
	if (n == 0 && !(var->flag & FLAG_PR))
		tmp = ft_zero(var, 0);
	else
		tmp = to_ubaseup(n, 16);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if ((var->flag & FLAG_DI) && !(var->flag & FLAG_ZE) && n != 0)
		tmp = ft_strjoin_free("0X", tmp, 3);
	if (var->width)
		tmp = ft_space(tmp, var);
	if ((var->flag & FLAG_DI) && (var->flag & FLAG_ZE) && n != 0)
		tmp = ft_strjoin_free("0X", tmp, 3);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}
