/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 12:49:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/12/21 15:29:49 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"

void	ft_putstr_spec(char *s)
{
	char	*p;

	p = s;
	while (*p != '\0')
	{
		if (*p == '\xFF')
		{
			*p = '\0';
			ft_putstr(s);
			ft_putchar('\0');
			s = p + 1;
		}
		p++;
	}
	ft_putstr(s);
}

void	ft_putstr_spec_fd(char *s, int fd)
{
	char	*p;

	p = s;
	while (*p != '\0')
	{
		if (*p == '\xFF')
		{
			*p = '\0';
			ft_putstr_fd(s, fd);
			ft_putchar_fd('\0', fd);
			s = p + 1;
		}
		p++;
	}
	ft_putstr_fd(s, fd);
}
