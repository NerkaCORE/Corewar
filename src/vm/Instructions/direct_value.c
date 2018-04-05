/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:44:17 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/12/21 15:44:18 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** this function takes four char bytes and puts them into
** an int using bit operators.
*/

unsigned int	trans_four_bytes(char *transfer_bytes)
{
	unsigned int	value;

	value = 0;
	value |= (transfer_bytes[0] << 24 & 0xff000000);
	value |= (transfer_bytes[1] << 16 & 0xff0000);
	value |= (transfer_bytes[2] << 8 & 0xff00);
	value |= (transfer_bytes[3] << 0 & 0xff);
	return (value);
}

/*
** this function puts four bytes into a string for
** further conversion into an unsigned int.
*/

char			*get_dir_value_quatre(t_data *data, t_listb *elem, int prm_pos)
{
	char	*four_bytes;
	int		i;
	int		k;

	k = 0;
	i = (elem->pc + prm_pos) % MEM_SIZE;
	four_bytes = ft_strnew(5);
	while (k < REG_SIZE)
	{
		four_bytes[k++] = data->map[i % MEM_SIZE];
		i++;
	}
	return (four_bytes);
}

/*
** called from parameters.
** this function gets the direct value,
** whether it's on four or two bytes.
*/

unsigned int	get_dir_value(t_data *data, t_listb *elem, int *prm_pos)
{
	unsigned int	dir_val;
	char			*bytes;

	dir_val = 0;
	bytes = NULL;
	if (elem->dir_by == 0)
	{
		bytes = get_dir_value_quatre(data, elem, (*prm_pos));
		dir_val = trans_four_bytes(bytes);
		(*prm_pos) = (*prm_pos) + 4;
	}
	else if (elem->dir_by == 1)
	{
		bytes = get_two_bytes(data, elem, (*prm_pos));
		dir_val = trans_two_bytes(bytes);
		(*prm_pos) = (*prm_pos) + 2;
	}
	return (dir_val);
}
