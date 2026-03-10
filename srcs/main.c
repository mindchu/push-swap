/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:14:12 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/11 05:23:16 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !is_sorted(*stack_a))
		swap_move(stack_a, NULL, "sa");
	else if (size == 3)
		small_sort(stack_a);
	else if (size > 3 && !is_sorted(*stack_a))
		big_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!check_input(av))
		put_error();
	stack_a = create_stack(ac, av);
	stack_b = NULL;
	size = get_stack_size(stack_a);
	get_main_index(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	free_safealloc();
	return (0);
}
