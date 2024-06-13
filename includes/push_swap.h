/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:55:31 by aattak            #+#    #+#             */
/*   Updated: 2024/06/13 17:18:33 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

// Input-Output Functions
t_stack	*create_stack(int ac, char **av);
int		is_stack_sorted(t_stack *stack_a, t_stack *stack_b);
char	**ft_split(char const *s, size_t *n_words);
void	free_split(char **split, size_t n_words);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *str, int fd);

// Linked Lists Operations
void	ft_lstadd_front(t_stack **list, t_stack *new_node);
void	ft_lstadd_back(t_stack **list, t_stack *new_node);
t_stack	*ft_lstnew(int data);
void	ft_lstclear(t_stack *list);
t_stack	*ft_lstlast(t_stack *list);
int		ft_lstsize(t_stack *list);

// Stack Operations		// to use when implementing the checker
t_stack	*pop_stack(t_stack **stack);
t_stack	*reverse_pop_stack(t_stack **stack);
void	push_stack(t_stack **to_push, t_stack **to_pop);
void	swap_stack(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);

// Stack Sort Instructions		// DON'T USE WITH CHECKER cuz they print to stdout.
void	swap_stack_a(t_stack **stack_a);
void	swap_stack_b(t_stack **stack_b);
void	swap_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	push_stack_a(t_stack **stack_a, t_stack **stack_b);
void	push_stack_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_stack_a(t_stack **stack_a);
void	rotate_stack_b(t_stack **stack_b);
void	rotate_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_stack_a(t_stack **stack_a);
void	reverse_rotate_stack_b(t_stack **stack_b);
void	reverse_rotate_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b);

#endif
