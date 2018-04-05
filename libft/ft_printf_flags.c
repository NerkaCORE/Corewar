/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:06:50 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:10 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

int			ft_check_flag(t_var *var)
{
	if (var->form[var->i] == '#' && (var->flag |= FLAG_DI))
		return (1);
	else if (var->form[var->i] == '0' && (var->flag |= FLAG_ZE))
		return (1);
	else if (var->form[var->i] == '-' && (var->flag |= FLAG_NEG))
		return (1);
	else if (var->form[var->i] == '+' && (var->flag |= FLAG_POS))
		return (1);
	else if (var->form[var->i] == ' ' && (var->flag |= FLAG_SP))
		return (1);
	else
		return (0);
}

int			ft_check_modif(t_var *var)
{
	if (var->form[var->i] == 'h' && var->form[var->i + 1] == 'h' &&
			(var->i += 1))
	{
		var->flag |= FLAG_HH;
		return (1);
	}
	else if (var->form[var->i] == 'l' && var->form[var->i + 1] == 'l' &&
			(var->i += 1))
	{
		var->flag |= FLAG_LL;
		return (1);
	}
	else if (var->form[var->i] == 'j' && (var->flag |= FLAG_J))
		return (1);
	else if (var->form[var->i] == 'L' && (var->flag |= FLAG_GL))
		return (1);
	else if (var->form[var->i] == 'h' && (var->flag |= FLAG_H))
		return (1);
	else if (var->form[var->i] == 'l' && (var->flag |= FLAG_L))
		return (1);
	else if (var->form[var->i] == 'z' && (var->flag |= FLAG_Z))
		return (1);
	else
		return (0);
}

int			ft_verif_flag(t_var *var)
{
	if ((var->form[var->i] == 'c' || var->form[var->i] == 's') &&
			(var->flag & FLAG_DI))
		var->flag ^= FLAG_DI;
	if ((var->flag & FLAG_POS) && (var->flag & FLAG_SP))
		var->flag ^= FLAG_SP;
	if ((var->flag & FLAG_NEG) && (var->flag & FLAG_ZE))
		var->flag ^= FLAG_ZE;
	if ((var->flag & FLAG_HH) && (var->flag & FLAG_H))
		var->flag ^= FLAG_HH;
	if ((var->flag & FLAG_LL) && (var->flag & FLAG_L))
		var->flag ^= FLAG_LL;
	if (((var->flag & FLAG_H) && (var->flag & FLAG_LL)) ||
			((var->flag & FLAG_H) && (var->flag & FLAG_L)))
		var->flag ^= FLAG_H;
	if (((var->flag & FLAG_HH) && (var->flag & FLAG_LL)) ||
			((var->flag & FLAG_HH) && (var->flag & FLAG_L)))
		var->flag ^= FLAG_HH;
	if ((var->flag & FLAG_PR) && var->flag & FLAG_ZE && !cc(var, 'c') &&
			!cc(var, 's') && !cc(var, 'S') && !cc(var, 'C') && !cc(var, '%'))
		var->flag ^= FLAG_ZE;
	if (var->flag & FLAG_J || var->flag & FLAG_Z)
		ft_verif_flag2(var);
	return (1);
}

void		ft_verif_flag2(t_var *var)
{
	if (var->flag & FLAG_J && var->flag & FLAG_Z)
		var->flag ^= FLAG_Z;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_L)
		var->flag ^= FLAG_L;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_LL)
		var->flag ^= FLAG_LL;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_H)
		var->flag ^= FLAG_H;
	if ((var->flag & FLAG_J || var->flag & FLAG_Z) && var->flag & FLAG_HH)
		var->flag ^= FLAG_HH;
}

int			cc(t_var *var, char c)
{
	if (var->form[var->i] == c)
		return (1);
	return (0);
}
