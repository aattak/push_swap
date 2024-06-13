/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:47:34 by aattak            #+#    #+#             */
/*   Updated: 2024/06/13 18:00:35 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	swap_instructions(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		swap_stack(stack_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap_stack(stack_b);
	else if (!ft_strcmp(instruction, "ss\n"))
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	else
		return (1);
	return (0);
}

int	push_instructions(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		push_stack(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "pb\n"))
		push_stack(stack_b, stack_a);
	else
		return (1);
	return (0);
}

int	rotate_instructions(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "ra\n"))
		rotate_stack(stack_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate_stack(stack_b);
	else if (!ft_strcmp(instruction, "rr\n"))
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
	else if (!ft_strcmp(instruction, "rra\n"))
		reverse_rotate_stack(stack_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		reverse_rotate_stack(stack_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_b);
	}
	else
		return (1);
	return (0);
}

int	apply_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction)
{
	int	is_error;

	is_error = 1;
	if (instruction[0] == 's')
		is_error = swap_instructions(stack_a, stack_b, instruction);
	else if (instruction[0] == 'p')
		is_error = push_instructions(stack_a, stack_b, instruction);
	else if (instruction[0] == 'r')
		is_error = rotate_instructions(stack_a, stack_b, instruction);
	return (is_error);
}
