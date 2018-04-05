/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_resol_ld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:30:10 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:56:50 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

int					ft_spe_ld(t_var *var)
{
	char			*tmp;

	tmp = ft_ld(var);
	if (var->flag & FLAG_PR && var->preci == 0)
		tmp = ft_strrevchr(tmp, '.');
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int					ft_spe_eld(t_var *var)
{
	char			*tmp;
	char			*ptr;

	tmp = ft_ld(var);
	if (ft_strcmp(tmp, "inf") != 0 && ft_strcmp(tmp, "-inf") != 0)
		tmp = ft_exp(var, tmp, 0);
	if (var->flag & FLAG_PR && var->preci == 0)
	{
		ptr = ft_strdup(tmp);
		tmp = ft_strrevchr(tmp, '.');
		tmp = ft_strjoin_free(tmp, ft_strchr(ptr, '.'), 1);
		ft_memdel((void **)&ptr);
	}
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int					ft_spe_gld(t_var *var)
{
	char			*tmp;
	int				neg;
	int				i;

	i = norm_gl(var, &tmp);
	neg = 0;
	if (tmp[0] == '-')
		neg = 1;
	while (tmp[i - 1] == '0')
	{
		i--;
		tmp[i] = '\0';
	}
	if (tmp[i - 1] == '.')
		tmp[i - 1] = '\0';
	if ((int)ft_strlen(tmp) > var->preci + neg || (!(ft_strchr(tmp, '.')
					&& (int)ft_strlen(tmp) > var->preci + neg + 1)))
	{
		var->preci++;
		tmp = ft_exp(var, tmp, 1);
	}
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

char				*ft_exp(t_var *var, char *str, int p)
{
	char			*tmp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (str[i] && str[i] != '.')
		i++;
	while (i > 1)
	{
		if (str[i - 2] == '-')
			break ;
		str[i] = str[i - 1];
		str[i - 1] = '.';
		i--;
		j++;
	}
	ft_memset((str + (ft_strlen(str) - j + p)), '\0', j);
	if (!(tmp = norm_exp(var, str, j)))
		return (NULL);
	return (tmp);
}

char				*ft_ld(t_var *var)
{
	long double		ld;
	char			*tmp;
	size_t			i;

	i = 0;
	if (var->flag & FLAG_GL)
		ld = va_arg(var->ap, long double);
	else
		ld = va_arg(var->ap, double);
	if (var->flag & FLAG_PR)
		tmp = ldtoa(var, ld, var->preci);
	else
		tmp = ldtoa(var, ld, 6);
	while (tmp[i] == '0' || tmp[i] == '.' || tmp[i] == '-')
		i++;
	if (i == ft_strlen(tmp) && ld != 0)
	{
		if (tmp[0] != '-')
			tmp = ft_strjoin_free("1", tmp, 3);
		else if ((tmp[0] = '1'))
			tmp = ft_strjoin_free("-", tmp, 3);
	}
	if (ld == 0)
		tmp = norm_ld(tmp);
	return (tmp);
}
