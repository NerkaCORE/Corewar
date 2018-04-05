/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:22:30 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/19 14:23:53 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft/libft.h"
#include <stdlib.h>

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*temporaire;
	t_list	*temporaire2;

	if (!lst || !f)
		return (NULL);
	temporaire2 = f(lst);
	if ((res = ft_lstnew(temporaire2->content, temporaire2->content_size)))
	{
		temporaire = res;
		lst = lst->next;
		while (lst)
		{
			temporaire2 = f(lst);
			if (!(temporaire->next = ft_lstnew(temporaire2->content,
									temporaire2->content_size)))
				return (NULL);
			temporaire = temporaire->next;
			lst = lst->next;
		}
	}
	return (res);
}
