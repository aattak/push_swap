/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:30:45 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 11:26:23 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	data_to_top(t_stack **stack, int data, void (*rotate)(t_stack **))
{
	while ((*stack)->data != data)
		rotate(stack);
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

int	get_min_index(t_stack *stack, int *min_value)
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
