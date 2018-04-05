/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:34:39 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/20 12:41:14 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

void			ft_init_tab(int (**tab_ft)(t_var *))
{
	tab_ft['%'] = &ft_spe_mod;
	tab_ft['c'] = &ft_spe_char;
	tab_ft['s'] = &ft_spe_str;
	tab_ft['d'] = &ft_spe_nb;
	tab_ft['i'] = &ft_spe_nb;
	tab_ft['u'] = &ft_spe_unb;
	tab_ft['o'] = &ft_spe_oct;
	tab_ft['x'] = &ft_spe_hex;
	tab_ft['X'] = &ft_spe_hexup;
	tab_ft['p'] = &ft_spe_mem;
	tab_ft['D'] = &ft_spe_l;
	tab_ft['O'] = &ft_spe_l;
	tab_ft['U'] = &ft_spe_l;
	tab_ft['C'] = &ft_spe_wchar;
	tab_ft['S'] = &ft_spe_wcstr;
	tab_ft['n'] = &ft_spe_intn;
	tab_ft['b'] = &ft_spe_ubin;
	tab_ft['B'] = &ft_spe_bin;
	tab_ft['f'] = &ft_spe_ld;
	tab_ft['F'] = &ft_spe_ld;
	tab_ft['e'] = &ft_spe_eld;
	tab_ft['E'] = &ft_spe_eld;
	tab_ft['g'] = &ft_spe_gld;
	tab_ft['G'] = &ft_spe_gld;
}

int				ft_pars_str(t_var *var)
{
	int			i;

	i = 0;
	if (!(var->tmp = (char *)malloc(sizeof(char) * (ft_strlen(var->form) + 1))))
		return (-1);
	while (var->form[var->i])
	{
		while (var->form[var->i] && (var->form[var->i]) != '%')
		{
			var->tmp[i] = var->form[var->i];
			i++;
			var->i++;
		}
		var->tmp[i] = '\0';
		var->str = ft_strjoin_free(var->str, var->tmp, 1);
		if (var->form[var->i] == '%' && ft_color(var))
			ft_pars_mod(var);
		i = 0;
	}
	ft_memdel((void **)&var->tmp);
	return (1);
}

char			*ft_add_char(char *str, char c, t_var *var)
{
	char		*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	if (var->width)
		tmp = ft_space(tmp, var);
	if (str)
		str = ft_strjoin_free(str, tmp, 1);
	else
		return (tmp);
	ft_memdel((void **)&tmp);
	return (str);
}

char			*ft_space(char *str, t_var *var)
{
	char		*tmp;

	tmp = NULL;
	var->width -= ft_strlen(str);
	norm_sp(var);
	if (var->width <= 0 && var->spe != 'c')
		return (str);
	if (!(tmp = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (0);
	ft_memset(tmp, '\0', var->width + 1);
	if (var->flag & FLAG_ZE)
		ft_memset(tmp, '0', var->width);
	else
		ft_memset(tmp, ' ', var->width);
	if (var->flag & FLAG_NEG && var->free != -1)
		str = ft_strjoin_free(str, tmp, 1);
	else if (var->flag & FLAG_NEG && var->free == -1)
		str = ft_strjoin(str, tmp);
	else if (var->free >= 0)
		str = ft_strjoin_free(tmp, str, 3);
	else
		str = ft_strjoin(tmp, str);
	ft_memdel((void **)&tmp);
	return (str);
}
