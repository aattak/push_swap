/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:48:40 by aattak            #+#    #+#             */
/*   Updated: 2024/06/12 09:42:00 by aattak           ###   ########.fr       */
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

void	print_2stacks(t_stack *stack_a, t_stack *stack_b)
{
		printf("stack a :\n");
		print_stack(stack_a);
		printf("stack b :\n");
		print_stack(stack_b);
}

void	test_sort_instructions(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack_b(stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	swap_stack_a(stack_a);
	print_2stacks(*stack_a, *stack_b); /////////

	swap_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	rotate_stack_a(stack_a);
	print_2stacks(*stack_a, *stack_b); /////////

	rotate_stack_b(stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	rotate_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	rotate_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	swap_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	reverse_rotate_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	reverse_rotate_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	swap_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	reverse_rotate_stacks_a_and_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_b(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////

	push_stack_a(stack_a, stack_b);
	print_2stacks(*stack_a, *stack_b); /////////
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b; ///// for test

	stack_b = NULL; /// for test
	if (ac > 1)
	{
		stack_a = create_stack(ac, av);
		//sort_stack(stack_a);

		/////// begin test
		print_2stacks(stack_a, stack_b);
		///////
		test_sort_instructions(&stack_a, &stack_b);
		//////// end test

		// must free the stack after it get sort!!
		ft_lstclear(stack_a);
		ft_lstclear(stack_b); //// for test
	}
	return (0);
}
