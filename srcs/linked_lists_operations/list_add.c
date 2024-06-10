/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:16:45 by aattak            #+#    #+#             */
/*   Updated: 2024/06/10 20:38:39 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_lstlast(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_front(t_stack **list, t_stack *new_node)
{
	if (list && new_node)
	{
		new_node->next = *list;
		*list = new_node;
	}
}

void	ft_lstadd_back(t_stack **list, t_stack *new_node)
{
	t_stack	*last;

	if (list && new_node)
	{
		if (!(*list))
			*list = new_node;
		else
		{
			last = ft_lstlast(*list);
			last->next = new_node;
		}
	}
}
