/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:44:38 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/12/21 15:44:40 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	move_pc_bad_registers(t_data *data, t_listb *elem, unsigned int *params,
		unsigned int *param_types)
{
	elem->pc = (elem->pc + data->dep) % MEM_SIZE;
	free_params(params, param_types);
}

void	exec_no_ocp(t_data *data, t_listb *elem, unsigned int *params,
		unsigned int *param_types)
{
	instr_no_ocp(data, elem, params);
	free_params(params, param_types);
}
