/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:45:56 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:04 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

void			ft_put_end(t_var *var)
{
	int			i;
	int			j;

	i = 0;
	j = var->ind - 1;
	while (var->ind > 0)
	{
		if (var->str[var->index[i]] == '*')
			var->str[var->index[i]] = '\0';
		else if (var->str[var->index[i] + 1] == '*')
			var->str[var->index[i] + 1] = '\0';
		var->ind--;
		i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_var		var;
	int			i;

	init_var(&var);
	va_start(var.ap, format);
	if (!(var.form = ft_strdup(format)))
		return (-1);
	ft_pars_str(&var);
	va_end(var.ap);
	i = ft_strlen(var.str);
	if (var.ind != 0)
		ft_put_end(&var);
	if (var.free == 1)
		ft_memdel((void **)&var.index);
	write(1, var.str, i);
	free_var(&var);
	return (i);
}
