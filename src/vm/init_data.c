/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unli-yaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:47:03 by unli-yaw          #+#    #+#             */
/*   Updated: 2017/12/21 15:47:04 by unli-yaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			test_int(char *s)
{
	long long	i;
	int			n;
	int			signe;

	signe = 1;
	n = 0;
	i = 0;
	if (!s)
		return (0);
	if (s[n] == '-')
	{
		n++;
		signe = -1;
	}
	while (s[n])
	{
		if (s[n] > '9' || s[n] < '0')
			return (1);
		i *= 10;
		i += s[n++] - '0';
	}
	i *= signe;
	if (i < 2147483647 && i > -2147483648)
		return (0);
	return (1);
}

void		init_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 4)
		tab[i++] = 0;
}

int			find_first_nb(int *tab)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (tab[i] != 0 && i < 4)
	{
		if (tab[i] == j)
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	tab[i] = j;
	return (j);
}

int			is_used(int nb, int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0 && i < 4)
	{
		if (tab[i] == nb)
			exit(ft_printf("\x1b[31m""Error : Champ ID already used\n"));
		i++;
	}
	tab[i] = nb;
	return (nb);
}

int			check_flag(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-v"))
			data->flag_visu = 1;
		if (!ft_strcmp(argv[i], "-dump"))
		{
			i++;
			if (argv[i] != NULL && !test_int(argv[i]))
				data->flag_dump = ft_atoi(argv[i]);
			else
			{
				ft_printf("\x1b[31m""Error : Incorrect value for dump\n");
				exit(0);
			}
		}
		i++;
	}
	if (data->flag_visu && data->flag_dump > -1)
		exit(ft_printf("\x1b[31m""Error : Too many flags\n"));
	return (0);
}
