/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:55:31 by aattak            #+#    #+#             */
/*   Updated: 2024/06/10 17:39:58 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	int				data;
	struct s_stack	*previous; ///// maybe it's useless cuz i don't need double linked list
	struct s_stack	*next;
}	t_stack;

// Linked Lists Operations

// Stack Operations		// to use when implementing the checker
t_stack	*pop_stack();
t_stack	*reverse_pop_stack();
void	push_stack();
void	swap_stack();
void	rotate_stack();
void	reverse_rotate_stack();

// Stack Sort Instructions		// DON'T USE WITH CHECKER cuz they print to stdout.
void	swap_stack_a();
void	swap_stack_b();
void	swap_stack_a_and_stack_b();
void	push_stack_a();
void	push_stack_b();
void	rotate_stack_a();
void	rotate_stack_b();
void	rotate_stack_a_and_stack_b();
void	reverse_rotate_stack_a();
void	reverse_rotate_stack_b();
void	reverse_rotate_stack_a_and_stack_b();

#endif
