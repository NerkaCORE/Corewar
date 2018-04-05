/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_preci.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:30:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:18 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

char		*ft_preci_nb(char *str, t_var *var)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!var->preci && (var->flag & FLAG_PR) && str[0] == '0')
		return (NULL);
	if (ft_strlen(str) >= (size_t)var->preci)
		return (str);
	if (!(tmp = (char *)malloc(sizeof(ft_strlen(str) + var->preci + 1))))
		return (0);
	ft_bzero(tmp, (ft_strlen(str) + var->preci + 1));
	j = var->preci - ft_strlen(str);
	ft_memset(tmp, '0', j);
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	ft_memdel((void **)&str);
	return (tmp);
}

char		*ft_preci_str(char *str, t_var *var)
{
	char	*tmp;
	int		i;
	int		j;

	j = ft_strlen(str) - ((ft_strlen(str) - var->preci));
	i = 0;
	if (ft_strlen(str) <= (size_t)var->preci)
		return (str);
	if (!(tmp = (char*)malloc(sizeof(char) * (j + 1))))
		return (0);
	ft_bzero(tmp, j + 1);
	while (j > 0)
	{
		tmp[i] = str[i];
		i++;
		j--;
	}
	return (tmp);
}
