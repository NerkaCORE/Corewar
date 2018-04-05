/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_norm1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:23:32 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/14 14:53:16 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/printf/ft_printf.h"

char		*norm_ld(char *tmp)
{
	ft_memdel((void **)&tmp);
	tmp = ft_strdup("0.000000");
	return (tmp);
}

char		*norm_exp(t_var *var, char *str, int j)
{
	char	*tmp;

	tmp = NULL;
	if (str[ft_strlen(str) - 1] == '0')
		str[ft_strlen(str) - 1] = '\0';
	if (str[ft_strlen(str) - 1] == '.')
		str[ft_strlen(str) - 1] = '\0';
	if (j < 10)
		str = ft_strjoin_free(str, ft_strjoin((var->form[var->i] ==
						'E' ? "E+0" : "e+0"), ft_itoa(j)), 3);
	else
		str = ft_strjoin_free(str, ft_strjoin((var->form[var->i] ==
						'E' ? "E+" : "e+"), ft_itoa(j)), 3);
	if (!(tmp = ft_strdup(str)))
		return (NULL);
	ft_memdel((void **)&str);
	return (tmp);
}

int			norm_gl(t_var *var, char **tmp)
{
	if (var->form[var->i] == 'G')
		var->form[var->i] = 'E';
	if ((var->flag & FLAG_PR) && !var->preci)
		var->preci = 1;
	else if (!(var->flag & FLAG_PR))
		var->preci = 6;
	*tmp = ft_ld(var);
	return (ft_strlen(*tmp));
}

char		*ft_strrevchr(char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (!s || !*s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * ((ft_strlen(s) + 1)))))
		return (NULL);
	ft_bzero(str, ft_strlen(s));
	while (s[i] != '\0' && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}
