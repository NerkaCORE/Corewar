/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:47:33 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/12/21 15:47:34 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		set_desc_pc(t_data *data)
{
	t_desc	*tmp;
	t_listb	*ptr;

	tmp = data->desc;
	while (tmp)
	{
		ptr = data->begin;
		tmp->pc = -1;
		while (tmp->pc == -1)
		{
			if (tmp->nb_champ == ptr->nb_champ)
				tmp->pc = ptr->pc;
			ptr = ptr->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	clear_pc(t_data *data)
{
	int	x_y[2];
	int	*pc;
	int	i;
	int	nb_champ;

	pc = set_array_pc(data->begin);
	i = 0;
	x_y[0] = 1;
	x_y[1] = 16;
	while (x_y[1] < 65)
	{
		while (x_y[0] < 192)
		{
			if ((nb_champ = find_pc_pos(data->begin, pc, data->nb_champ, i)) \
					!= -1)
				display_classique(data, i, x_y, nb_champ);
			x_y[0] += 3;
			i++;
		}
		x_y[1]++;
		x_y[0] = 1;
	}
}

void	clear_died_pc(t_data *data, t_listb *elem)
{
	int	x_y[2];
	int	i;

	i = 0;
	x_y[0] = 1;
	x_y[1] = 16;
	while (x_y[1] < 65)
	{
		while (x_y[0] < 192)
		{
			if (i == elem->pc)
				display_classique(data, i, x_y, elem->nb_champ);
			x_y[0] += 3;
			i++;
		}
		x_y[1]++;
		x_y[0] = 1;
	}
	refresh();
}

void	print_pc(t_data *data)
{
	int	x_y[2];
	int	*pc;
	int	i;
	int	nb_champ;

	pc = set_array_pc(data->begin);
	i = 0;
	x_y[0] = 1;
	x_y[1] = 16;
	while (x_y[1] < 65)
	{
		while (x_y[0] < 192)
		{
			if ((nb_champ = find_pc_pos(data->begin, pc, data->nb_champ, i)) \
					!= -1)
				display_pc(data, i, x_y, nb_champ);
			x_y[0] += 3;
			i++;
		}
		x_y[1]++;
		x_y[0] = 1;
	}
	refresh();
}

void	print_index(t_data *data, t_listb *elem, int index)
{
	int	x_y[2];
	int	*pc;
	int	nb_champ;
	int	i;

	i = 0;
	pc = set_array_pc(data->begin);
	x_y[0] = 1;
	x_y[1] = 16;
	while (x_y[1] < 65)
	{
		while (x_y[0] < 192)
		{
			if (i == index)
				(nb_champ = find_pc_pos(data->begin, pc, data->nb_champ, i))
				!= -1 ? display_pc(data, i, x_y, nb_champ) :
				display_classique(data, i, x_y, elem->nb_champ);
			x_y[0] += 3;
			i++;
		}
		x_y[1]++;
		x_y[0] = 1;
	}
	refresh();
}
