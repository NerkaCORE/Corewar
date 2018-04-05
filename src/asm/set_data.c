/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:56:46 by ybitton           #+#    #+#             */
/*   Updated: 2017/11/21 19:29:04 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	clean_label(t_tree *tree)
{
	while (tree)
	{
		tree->key = tree->key - 1;
		tree = tree->next;
	}
}
