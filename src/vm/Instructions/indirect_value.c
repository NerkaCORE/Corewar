/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:44:29 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/12/21 15:44:31 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

unsigned int	trans_two_bytes(char *transfer_bytes)
{
	unsigned int	value;

	value = 0;
	value |= (transfer_bytes[0] << 8 & 0xff00);
	value |= (transfer_bytes[1] << 0 & 0xff);
	return (value);
}

char			*get_two_bytes(t_data *data, t_listb *elem, int prm_pos)
{
	char	*two_bytes;
	int		i;
	int		k;

	k = 0;
	i = (elem->pc + prm_pos) % MEM_SIZE;
	two_bytes = NULL;
	two_bytes = ft_strnew(5);
	while (k < IND_SIZE)
	{
		two_bytes[k] = data->map[i % MEM_SIZE];
		i++;
		k++;
	}
	return (two_bytes);
}

unsigned int	get_ind_value(t_data *data, t_listb *elem, int prm_pos)
{
	int		ind_value;
	char	*transfer_bytes;

	ind_value = 0;
	transfer_bytes = NULL;
	transfer_bytes = get_two_bytes(data, elem, prm_pos);
	ind_value = trans_two_bytes(transfer_bytes);
	return (ind_value);
}
