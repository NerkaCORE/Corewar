/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:44:04 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/12/21 15:44:05 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		apply_add(t_data *data, t_listb *elem, unsigned int *params,
		unsigned int *param_types)
{
	int store;
	int i;

	i = 0;
	store = 0;
	(void)data;
	if (param_types[0] != REG_CODE || param_types[1] != REG_CODE ||
			param_types[2] != REG_CODE || params[0] > 15 ||
			params[1] > 15 || params[2] > 15)
		return ;
	while (param_types[i] != 0)
	{
		if (param_types[i] != REG_CODE)
			return ;
		i++;
	}
	store = elem->reg_number[params[0]] + elem->reg_number[params[1]];
	if (store == 0)
		elem->carry = 1;
	else
		elem->carry = 0;
	elem->reg_number[params[2]] = store;
}

void		apply_sub(t_data *data, t_listb *elem, unsigned int *params,
		unsigned int *param_types)
{
	int store;
	int i;

	i = 0;
	store = 0;
	(void)data;
	if (param_types[0] != REG_CODE || param_types[1] != REG_CODE ||
			param_types[2] != REG_CODE || params[0] > 15 ||
			params[1] > 15 || params[2] > 15)
		return ;
	while (param_types[i] != 0)
	{
		if (param_types[i] != REG_CODE)
			return ;
		i++;
	}
	store = elem->reg_number[params[0]] - elem->reg_number[params[1]];
	if (store == 0)
		elem->carry = 1;
	else
		elem->carry = 0;
	elem->reg_number[params[2]] = store;
}
