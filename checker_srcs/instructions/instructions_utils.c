/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:59:32 by aattak            #+#    #+#             */
/*   Updated: 2024/06/13 18:04:13 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}

void	instruction_error(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(instruction);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
