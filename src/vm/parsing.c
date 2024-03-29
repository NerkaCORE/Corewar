/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:47:08 by unli-yaw          #+#    #+#             */
/*   Updated: 2018/01/31 16:49:49 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			stock_desc(t_data *data, char *buf, int nb)
{
	unsigned int		i;
	t_desc				*elem;

	i = 0;
	elem = create_desc(&data->desc, nb);
	i = (buf[0] << 24 & 0xff000000) | (buf[1] << 16 & 0xff0000) |
		(buf[2] << 8 & 0xff00) | (buf[3] & 0xff);
	if (i != COREWAR_EXEC_MAGIC)
		exit(ft_printf("\x1b[31m""ERROR : File or Magic invalid\n"));
	ft_strncpy(elem->name, buf + 4, 128);
	elem->size = (buf[136] << 24 & 0xff000000) | (buf[137] << 16 & 0xff0000) |
		(buf[138] << 8 & 0xff00) | (buf[139] & 0xff);
	ft_strcpy(elem->desc, buf + 140);
	return (elem->size);
}

int			recup_champ_nb(t_desc *begin)
{
	t_desc *elem;

	elem = begin;
	while (elem->next)
		elem = elem->next;
	return (elem->nb_champ);
}

void		recup_champ(t_data *data, char **argv, int i, int nb)
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
	static int	n = 0;
	int			size[2];

	buf[BUFF_SIZE] = '\0';
	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
		exit(ft_printf("\x1b[31m""Error : Invalid path\n"));
	read(fd, buf, BUFF_SIZE);
	size[0] = stock_desc(data, buf, nb);
	size[1] = n;
	data->begin = create_elem(data->begin, recup_champ_nb(data->desc), n);
	while ((read(fd, data->map + n, 1)) && n <= MEM_SIZE)
	{
		n++;
	}
	if (n > MEM_SIZE)
		exit(write(1, "Champ size is too big\n", 22));
	size[1] = n - size[1];
	if (size[0] != size[1])
		exit(write(1, "Size indicated is too big\n", 26));
	if (size[0] > CHAMP_MAX_SIZE)
		exit(write(1, "Champ size incorrect\n", 21));
	n = (n / (MEM_SIZE / data->nb_champ) + 1) * (MEM_SIZE / data->nb_champ);
}

void		is_number_set(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!(ft_strcmp(argv[i], "-n")))
		{
			data->nb_champ -= 1;
			if (!(test_int(argv[i + 1])))
				data->nb_champ -= 1;
		}
		i++;
	}
}

void		parse_map(int argc, char **argv, t_data *data)
{
	int		i;
	int		nb;

	nb = 0;
	i = 1 + data->flag_visu;
	data->nb_champ = argc - 1 - data->flag_visu;
	is_number_set(argc, argv, data);
	if (data->flag_dump >= 0 && (data->nb_champ -= 2))
		i += 2;
	data->nb_champ > MAX_PLAYERS ? exit(ft_printf(
				"Error : Too many champs loaded\n")) : 0;
	i == argc ? exit(ft_printf("\x1b[31m""Error : No champ loaded\n")) : 0;
	while (i < argc)
	{
		if (!(ft_strcmp(argv[i], "-n")))
		{
			if (test_int(argv[++i]))
				exit(ft_printf("\x1b[31m""Error : Champ ID incorrect\n"));
			nb = ft_atoi(argv[i++]);
		}
		recup_champ(data, argv, i++, nb);
		nb = 0;
	}
}
