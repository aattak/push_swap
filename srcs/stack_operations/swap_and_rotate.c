/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:14:13 by aattak            #+#    #+#             */
/*   Updated: 2024/06/11 18:26:03 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (*stack)
	{
		if ((*stack)->next)
		{
			tmp_1 = pop_stack(stack);
			tmp_2 = pop_stack(stack);
			ft_lstadd_front(stack, tmp_1);
			ft_lstadd_front(stack, tmp_2);
		}
	}
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = pop_stack(stack);
	ft_lstadd_back(stack, tmp);
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = reverse_pop_stack(stack);
	ft_lstadd_front(stack, tmp);
}
