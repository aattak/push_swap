/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aattak <aattak@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:23:09 by aattak            #+#    #+#             */
/*   Updated: 2024/06/12 19:31:45 by aattak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
rotate_and_push_to_b

	if (a->data <= size_b)
		push_a_to_b
	else if (a->data <= size_b + RANGE)
	{
		push_a_to_b
		//rotate_b
	}
	else if (get_last(stack_a)->data <= size_b + RANGE)
		r_rotate_a
	else
		rotate_a
*/

void	rotate_and_push_to_b(t_stack **a, t_stack **b)
{
	int	rangel
	if (size_a <= 100)
		range = size_a / 5;
	else
		range = size_a / 10;
	int size_b = stack_size(b);
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	if (tmp_a->data <= size_b)

}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	// if stack sorted >> return
	// if stack_size == 2 >> swap >> return
	// if stack_size == 3 >> sort_stack_three >> return
	// if stack size == 4 >> push_min_to_b >> sort_stack_three >> push_b_to_a >> return
	// if stack size == 5 >> push_min_to_b >> sort_four >> push_b_to_a >> return
	// get_indexes(stack_a)
	// while (*stack_a) >> rotate_and_push_to_b
	// while (*stack_b) >> push_max_to_a
}
/*
get_stack_a(int set, t_stack **stack_a)
{
	static t_stack	**p_stack_a;
	if (set)
		p_stack_a = stack_a
	return p_stack_a;

}

if (!malloc_return)
{
	free_stack(get_stack_a(GET, NULL));
	free_stack(get_stack_a(SET, NULL));
}
*/
/*
get_indexes
	stack_to_array
	sort_array
	while (tmp_stack_a)
	{
		tmp_stack_a->index = get_index(tmp_stack_a->value)
		tmp_stack_a = tmp_stack_a->next;
	}

stack a 		= 5 4 6 3

array   		= 3 4 5 6

stack_a->index  = 2 1 3 0
*/
/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
