/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:14:12 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/13 02:27:26 by chutterm         ###   ########.fr       */
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
	char	*joined_str;
	char	**args;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	joined_str = join_args(ac, av);
	args = ft_split(joined_str, ' ');
	free(joined_str);
	if (!check_input(args))
		put_error(args);
	stack_a = create_stack(args);
	free_matrix(args);
	stack_b = NULL;
	size = get_stack_size(stack_a);
	get_main_index(stack_a, size);
	push_swap(&stack_a, &stack_b, size);
	free_safealloc();
	return (0);
}
