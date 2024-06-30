/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:23:09 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 11:11:25 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b, int size_stack_a)
{
	int	range;
	int	size_stack_b;

	size_stack_b = 0;
	range = (size_stack_a * 11) / 100;
	while (*stack_a)
	{
		if (size_stack_a > 200)
			range = (size_stack_a * 11) / 100;
		if ((*stack_a)->data <= size_stack_b)
			push_stack_b(stack_a, stack_b, &size_stack_a, &size_stack_b);
		else if ((*stack_a)->data <= size_stack_b + range)
		{
			push_stack_b(stack_a, stack_b, &size_stack_a, &size_stack_b);
			rotate_stack_b(stack_b);
		}
		else if (ft_lstlast(*stack_a)->data <= size_stack_b + range)
			reverse_rotate_stack_a(stack_a);
		else
			rotate_stack_a(stack_a);
	}
}

void	push_max(t_stack **stack_a, t_stack **stack_b, int size_stack_b)
{
	int	max_index;
	int	max_value;

	while (*stack_b)
	{
		max_index = get_max_index(*stack_b, &max_value);
		if (max_index <= size_stack_b / 2)
			data_to_top(stack_b, max_value, rotate_stack_b);
		else
			data_to_top(stack_b, max_value, reverse_rotate_stack_b);
		push_stack_a(stack_a, stack_b, NULL, &size_stack_b);
	}
}

void	push_min(t_stack **stack_a, t_stack **stack_b, int *size_stack_a)
{
	int	min_index;
	int	min_value;

	min_index = get_min_index(*stack_a, &min_value);
	if (min_index <= (*size_stack_a) / 2)
		data_to_top(stack_a, min_value, rotate_stack_a);
	else
		data_to_top(stack_a, min_value, reverse_rotate_stack_a);
	push_stack_b(stack_a, stack_b, size_stack_a, NULL);
}

void	sort_three(t_stack **stack_a)
{
	int	max_value;

	get_max_index(*stack_a, &max_value);
	if ((*stack_a)->data == max_value)
		rotate_stack_a(stack_a);
	else if ((*stack_a)->next->data == max_value)
		reverse_rotate_stack_a(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_stack_a(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack_a;

	size_stack_a = ft_lstsize(*stack_a);
	if (size_stack_a == 2)
		swap_stack_a(stack_a);
	if (size_stack_a == 5)
		push_min(stack_a, stack_b, &size_stack_a);
	if (size_stack_a == 4)
		push_min(stack_a, stack_b, &size_stack_a);
	if (size_stack_a == 3)
	{
		sort_three(stack_a);
		if (*stack_b)
			push_stack_a(stack_a, stack_b, NULL, NULL);
		if (*stack_b)
			push_stack_a(stack_a, stack_b, NULL, NULL);
	}
	if (size_stack_a > 5)
	{
		apply_indexes(*stack_a, size_stack_a);
		fill_stack_b(stack_a, stack_b, size_stack_a);
		push_max(stack_a, stack_b, size_stack_a);
	}
}
