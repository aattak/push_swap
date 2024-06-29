/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:10:22 by aattak            #+#    #+#             */
/*   Updated: 2024/06/15 21:51:27 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handler(t_stack *stack, char **split, size_t n_words, char *str)
{
	ft_lstclear(stack);
	free_split(split, n_words);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	ft_isduplicate(t_stack *stack, int nbr)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_stack_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b)
	{
		while (stack_a->next)
		{
			if (stack_a->data > stack_a->next->data)
				return (0);
			stack_a = stack_a->next;
		}
		return (1);
	}
	return (0);
}
