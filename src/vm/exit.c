/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:32:55 by unli-yaw          #+#    #+#             */
/*   Updated: 2018/02/13 15:32:56 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		exit_programm(t_data *data)
{
	t_desc	*tmp;

	tmp = data->desc;
	while (tmp->next != NULL)
	{
		ft_memdel((void **)&tmp->name);
		ft_memdel((void **)&tmp->desc);
		tmp = tmp->next;
	}
	tmp = data->desc;
	while (tmp->next != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
}
