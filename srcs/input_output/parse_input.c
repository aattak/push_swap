/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:57:40 by aattak            #+#    #+#             */
/*   Updated: 2024/06/19 13:19:28 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	split_to_stack(t_stack **stack, char **split, size_t n_words)
{
	long	nbr;
	size_t	i;
	t_stack	*node;

	i = 0;
	while (split[i])
	{
		nbr = ft_atoil(split[i]);
		if (nbr > INT_MAX || ft_isduplicate(*stack, (int)nbr))
			error_handler(*stack, split, n_words, "Error\n");
		node = ft_lstnew(nbr);
		if (!node)
			error_handler(*stack, split, n_words, "Malloc Error\n");
		ft_lstadd_back(stack, node);
		i++;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	int		i;
	size_t	n_words;
	char	**split;
	t_stack	*stack;

	stack = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], &n_words);
		if (!split)
			error_handler(stack, NULL, 0, "Malloc Error\n");
		if (!n_words)
			error_handler(stack, split, n_words, "Error\n");
		split_to_stack(&stack, split, n_words);
		free_split(split, n_words);
		i++;
	}
	return (stack);
}
