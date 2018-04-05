/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_resol_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:08:02 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:19 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

int					ft_spe_intn(t_var *var)
{
	int				*i;

	i = (int*)va_arg(var->ap, void *);
	*i = ft_strlen(var->str);
	return (1);
}

char				*ft_getbit(uintmax_t n)
{
	unsigned int	t;
	int				i;
	int				j;
	char			*ret;
	int				k;

	ret = NULL;
	j = 0;
	i = 31;
	t = 1;
	k = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (33))))
		return (0);
	ft_bzero(ret, 33);
	while (i >= 0)
	{
		if (n & t << i)
			ret[k] = '1';
		else
			ret[k] = '0';
		i--;
		k++;
	}
	return (ret);
}

int					ft_spe_ubin(t_var *var)
{
	uintmax_t		n;
	char			*tmp;

	n = ft_get_uint(var);
	tmp = ft_getbit(n);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}

int					ft_spe_bin(t_var *var)
{
	intmax_t		n;
	char			*tmp;

	n = ft_get_int(var);
	if (n < 0)
		n = -n;
	tmp = ft_getbit(n);
	if (var->preci)
		tmp = ft_preci_nb(tmp, var);
	if (var->width)
		tmp = ft_space(tmp, var);
	var->str = ft_strjoin_free(var->str, tmp, 2);
	return (1);
}
