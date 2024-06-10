/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:55:07 by aattak            #+#    #+#             */
/*   Updated: 2024/06/10 16:16:35 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}
