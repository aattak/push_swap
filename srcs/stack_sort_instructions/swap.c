/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:53:12 by aattak            #+#    #+#             */
/*   Updated: 2024/06/10 18:18:32 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_stack_a(t_stack **stack_a)
{
	swap_stack(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_stack_b(t_stack **stack_b)
{
	swap_stack(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_putstr_fd("ss\n", 1);
}
