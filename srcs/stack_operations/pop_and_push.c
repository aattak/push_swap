/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:13:23 by aattak            #+#    #+#             */
/*   Updated: 2024/06/11 18:25:40 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*pop_stack(t_stack **stack)
{
	t_stack	*first_node;

	if (*stack)
	{
		first_node = *stack;
		*stack = (*stack)->next;
		first_node->next = NULL;
		return (first_node);
	}
	return (NULL);
}

t_stack	*reverse_pop_stack(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*new_last_node;

	new_last_node = *stack;
	if (*stack)
	{
		if ((*stack)->next)
		{
			while (new_last_node->next->next)
				new_last_node = new_last_node->next;
			last_node = new_last_node->next;
			new_last_node->next = NULL;
			return (last_node);
		}
		return (pop_stack(stack));
	}
	return (NULL);
}

void	push_stack(t_stack **to_push, t_stack **to_pop)
{
	t_stack	*tmp;

	tmp = pop_stack(to_pop);
	ft_lstadd_front(to_push, tmp);
}
