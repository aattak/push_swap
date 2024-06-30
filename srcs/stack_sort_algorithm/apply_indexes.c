/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_indexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:20:50 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 10:21:28 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	free(tab);
}
