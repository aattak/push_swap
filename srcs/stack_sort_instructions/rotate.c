/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:57:18 by aattak            #+#    #+#             */
/*   Updated: 2024/06/10 18:21:17 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_stack_a(t_stack **stack_a)
{
	rotate_stack(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_stack_b(t_stack **stack_b)
{
	rotate_stack(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_putstr_fd("rr\n", 1);
}
