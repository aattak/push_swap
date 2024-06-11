/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:57:40 by aattak            #+#    #+#             */
/*   Updated: 2024/06/11 21:04:53 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	error_handler(t_stack *stack, char **split, size_t n_words, char *str)
{
	ft_lstclear(stack);
	free_split(split, n_words);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	check_sign(char c, size_t *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoil(const char *str)
{
	int		sign;
	long	nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	sign = check_sign(str[i], &i);
	if (str[i] < '0' || str[i] > '9')
		return (((long)INT_MAX) + 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - 48;
		if ((nbr > INT_MAX && sign == 1) || (nbr > (long)(INT_MAX) + 1
			&& sign == -1))
			return (nbr);
		i++;
	}
	if (str[i])
		return (((long)INT_MAX) + 1);
	return (nbr * (long)sign);
}

void	split_to_stack(t_stack **stack, char **split, size_t n_words)
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
