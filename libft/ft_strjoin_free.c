/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:43:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/02/27 13:31:46 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char *s1, char *s2, int d)
{
	char	*str;
	int		len;

	str = NULL;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (d == 2)
	{
		ft_memdel((void **)&s1);
		ft_memdel((void **)&s2);
	}
	else if (d == 1)
		ft_memdel((void **)&s1);
	else if (d == 3)
		ft_memdel((void **)&s2);
	return (str);
}
