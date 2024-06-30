/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:50:49 by aattak            #+#    #+#             */
/*   Updated: 2024/06/30 07:49:26 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	main(int ac, char **av)
{
	char	*instruction;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac > 1)
	{
		stack_a = create_stack(ac, av);
		while (1)
		{
			instruction = get_next_line(0);
			if (!instruction)
				break ;
			if (apply_instruction(&stack_a, &stack_b, instruction))
				instruction_error(stack_a, stack_b, instruction);
			free(instruction);
		}
		if (is_stack_sorted(stack_a, stack_b))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
	}
	return (0);
}
