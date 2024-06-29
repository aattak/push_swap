/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:23:09 by aattak            #+#    #+#             */
/*   Updated: 2024/06/29 17:23:47 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
rotate_and_push_to_b(t_stack **a, t_stack **b)
{
	int	rangel
	if (size_a <= 100)
		range = size_a / 5;
	else
		range = size_a / 10;
	int size_b = stack_size(b);
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	if (tmp_a->data <= size_b)

}
*/

void	stack_to_tab(t_stack *stack_a, int *tab)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min = tab[i];
		while (j < size)
		{
			if (tab[j] < min)
			{
				tmp = tab[j];
				tab[j] = min;
				min = tmp;
			}
			j++;
		}
		tab[i] = min;
		i++;
	}
}

int	get_index(int *tab, int data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (tab[i] == data)
			return (i);
		i++;
	}
}

void	get_indexes(t_stack *stack_a, int *tab)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		tmp->data = get_index(tab, tmp->data);
		tmp = tmp->next;
	}
}

void	apply_indexes(t_stack *stack_a, int size_stack_a)
{
	int	*tab;

	tab = (int *)malloc(size_stack_a * sizeof(int));
	if (!tab)
		error_handler(stack_a, NULL, 0, "Malloc Error\n");
	stack_to_tab(stack_a, tab);
	sort_tab(tab, size_stack_a);
	get_indexes(stack_a, tab);
}

/*
rotate_and_push_to_b

	if (a->data < size_b)
		push_b
	else if (a->data <= size_b + RANGE)
	{
		push_b
		rotate_b
	}
	else if (get_last(stack_a)->data <= size_b + RANGE)
		reverse_rotate_a
	else
		rotate_a
*/

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
		{
			push_stack_b(stack_a, stack_b);
			size_stack_a--;
			size_stack_b++;
		}
		else if ((*stack_a)->data <= size_stack_b + range)
		{
			push_stack_b(stack_a, stack_b);
			rotate_stack_b(stack_b);
			size_stack_a--;
			size_stack_b++;
		}
		else if (ft_lstlast(*stack_a)->data <= size_stack_b + range)
			reverse_rotate_stack_a(stack_a);
		else
			rotate_stack_a(stack_a);
	}
}

int	get_max_index(t_stack *stack, int *max_value)
{
	int	i;
	int	max_index;

	max_index = 0;
	*max_value = stack->data;
	i = 1;
	stack = stack->next;
	while (stack)
	{
		if (stack->data > *max_value)
		{
			*max_value = stack->data;
			max_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_index);
}

void	data_to_top(t_stack **stack, int data, void (*rotate)(t_stack **))
{
	while ((*stack)->data != data)
		rotate(stack);
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
		push_stack_a(stack_a, stack_b);
		size_stack_b--;
	}
}

int get_min_index(t_stack *stack, int *min_value)
{
	int	i;
	int	min_index;

	min_index = 0;
	*min_value = stack->data;
	i = 1;
	stack = stack->next;
	while (stack)
	{
		if (stack->data < *min_value)
		{
			*min_value = stack->data;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
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
	push_stack_b(stack_a, stack_b);
	(*size_stack_a)--;
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
			push_stack_a(stack_a, stack_b);
		if (*stack_b)
			push_stack_a(stack_a, stack_b);
	}
	if (size_stack_a > 5)
	{
		apply_indexes(*stack_a, size_stack_a);
		fill_stack_b(stack_a, stack_b, size_stack_a);
		push_max(stack_a, stack_b, size_stack_a);
	}
}

/*

1 3 2	swap > rotate

2 1 3	swap

2 3 1	reverse_rotate

3 1 2	rotate

3 2 1	swap > reverse_rotate

*/
