/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:58:54 by aattak            #+#    #+#             */
/*   Updated: 2024/06/10 18:18:00 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_stack_a(t_stack **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_stack_b(t_stack **stack_b)
{
	reverse_rotate_stack(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
