/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:57:00 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 07:51:50 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

// Instructions Checking Functions
int		apply_instruction(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
int		rotate_instructions(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
int		push_instructions(t_stack **stack_a, t_stack **stack_b,
			char *instruction);
int		swap_instructions(t_stack **stack_a, t_stack **stack_b,
			char *instruction);

// Instructions Utils Functions
void	instruction_error(t_stack *stack_a, t_stack *stack_b,
			char *instruction);
int		ft_strcmp(char *s1, char *s2);

#endif
