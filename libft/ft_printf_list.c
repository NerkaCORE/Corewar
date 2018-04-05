/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:12:26 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:14 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

void		init_var(t_var *var)
{
	var->neg = 0;
	var->width = 0;
	var->preci = 0;
	var->flag = 0;
	var->arg = 0;
	var->pwc = 0;
	var->ind = 0;
	var->index = 0;
	var->i = 0;
	var->spe = 0;
	var->naze = 0;
	var->free = 0;
	var->str = NULL;
	var->ptr = NULL;
	var->form = NULL;
	var->tmp = NULL;
}

void		free_var(t_var *var)
{
	ft_memdel((void **)&var->str);
	ft_memdel((void **)&var->form);
	ft_memdel((void **)&var->tmp);
}
