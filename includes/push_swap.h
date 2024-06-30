/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:55:31 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 11:29:35 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

// Input-Output Functions
t_stack	*create_stack(int ac, char **av);
int		ft_isduplicate(t_stack *stack, int nbr);
int		is_stack_sorted(t_stack *stack_a, t_stack *stack_b);
char	**ft_split(char const *s, size_t *n_words);
long	ft_atoil(const char *str);
void	free_split(char **split, size_t n_words);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *str, int fd);
void	error_handler(t_stack *stack, char **split, size_t n_words, char *str);

// Linked Lists Operations
void	ft_lstadd_front(t_stack **list, t_stack *new_node);
void	ft_lstadd_back(t_stack **list, t_stack *new_node);
t_stack	*ft_lstnew(int data);
void	ft_lstclear(t_stack *list);
t_stack	*ft_lstlast(t_stack *list);
int		ft_lstsize(t_stack *list);

// Stack Operations
t_stack	*pop_stack(t_stack **stack);
t_stack	*reverse_pop_stack(t_stack **stack);
void	push_stack(t_stack **to_push, t_stack **to_pop);
void	swap_stack(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);

// Stack Sort Instructions
void	swap_stack_a(t_stack **stack_a);
void	swap_stack_b(t_stack **stack_b);
void	swap_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	push_stack_a(t_stack **stack_a, t_stack **stack_b, int *size_stack_a,
			int *size_stack_b);
void	push_stack_b(t_stack **stack_a, t_stack **stack_b, int *size_stack_a,
			int *size_stack_b);
void	rotate_stack_a(t_stack **stack_a);
void	rotate_stack_b(t_stack **stack_b);
void	rotate_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_stack_a(t_stack **stack_a);
void	reverse_rotate_stack_b(t_stack **stack_b);
void	reverse_rotate_stacks_a_and_b(t_stack **stack_a, t_stack **stack_b);

// Stack Sort Algorithm Functions
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	push_min(t_stack **stack_a, t_stack **stack_b, int *size_stack_a);
void	sort_three(t_stack **stack_a);
void	apply_indexes(t_stack *stack_a, int size_stack_a);
void	fill_stack_b(t_stack **stack_a, t_stack **stack_b, int size_stack_a);
void	push_max(t_stack **stack_a, t_stack **stack_b, int size_stack_b);

// Stack Sort Algorithm Utils Functions
void	data_to_top(t_stack **stack, int data, void (*rotate)(t_stack **));
int		get_max_index(t_stack *stack, int *max_value);
int		get_min_index(t_stack *stack, int *min_value);
void	stack_to_tab(t_stack *stack_a, int *tab);
void	sort_tab(int *tab, int size);
int		get_index(int *tab, int data);
void	get_indexes(t_stack *stack_a, int *tab);

#endif
