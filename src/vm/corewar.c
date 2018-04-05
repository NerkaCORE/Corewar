/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:46:42 by unli-yaw          #+#    #+#             */
/*   Updated: 2018/02/13 14:59:45 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	print_usage(void)
{
	ft_putendl_fd("usage:\t./corewar [-dump] [-v -n] player1 player2", 2);
	ft_putendl_fd("\t./corewar [-dump] [-v -n] player1 ... player4", 2);
	exit(ft_printf("\x1b[31m""Error : No champ loaded\n"));
}

int			main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
	{
		print_usage();
	}
	init_structur(&data);
	check_flag(argc, argv, &data);
	parse_map(argc, argv, &data);
	if (data.flag_visu == 1)
	{
		get_str_addr(data.map);
		aff_window(&data);
	}
	data.flag_slowmode == 1 ? turn_by_slowmode(&data) : turn_by_none(&data);
	end(&data);
	exit_programm(&data);
	return (0);
}

void		adjust_action_time(t_listb *elem, char pc)
{
	if (pc == 0x01 || pc == 0x04 || pc == 0x05 || pc == 0x0D)
		elem->action_time = 10;
	else if (pc == 0x02 || pc == 0x03)
		elem->action_time = 5;
	else if (pc == 0x06 || pc == 0x07 || pc == 0x08)
		elem->action_time = 6;
	else if (pc == 0x0A || pc == 0x0B)
		elem->action_time = 25;
	else if (pc == 0x09)
		elem->action_time = 20;
	else if (pc == 0x0C)
		elem->action_time = 800;
	else if (pc == 0x0E)
		elem->action_time = 50;
	else if (pc == 0x0F)
		elem->action_time = 1000;
	else if (pc == 0x10)
		elem->action_time = 2;
}

void		process_action(t_data *data, t_listb *elem)
{
	if ((!(data->map[elem->pc] >= 0x01 && data->map[elem->pc] <= 0x10)) &&
			!elem->action_time)
	{
		elem->pc++;
		elem->pc = elem->pc % MEM_SIZE;
		return ;
	}
	else
	{
		if (!(elem->action_time))
			adjust_action_time(elem, data->map[elem->pc]);
		if (elem->action_time)
		{
			elem->action_time--;
			if (!(elem->action_time))
				instruction_exec(data, elem);
		}
	}
}

void		turn(t_data *data)
{
	t_listb *elem;

	if (data == NULL || data->begin == NULL)
		return ;
	elem = data->begin;
	while (elem)
	{
		process_action(data, elem);
		elem = elem->next;
	}
	return ;
}
