/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:48:40 by aattak            #+#    #+#             */
/*   Updated: 2024/06/11 20:28:16 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	printf("\n-----------------\n");
	while (tmp)
	{
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n-----------------\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac > 1)
	{
		stack_a = create_stack(ac, av);
		//sort_stack(stack_a);
		// must free the stack after it get sort!!
		print_stack(stack_a);
		ft_lstclear(stack_a);
	}
	return (0);
}
