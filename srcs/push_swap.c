/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:48:40 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 08:51:08 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = create_stack(ac, av);
		if (!is_stack_sorted(stack_a, NULL))
			sort_stack(&stack_a, &stack_b);
		ft_lstclear(stack_a);
	}
	return (0);
}
