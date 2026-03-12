/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:00:25 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/13 00:35:56 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_main_index(t_stack *stack, int size)
{
	t_stack	*temp;
	t_stack	*max_node;

	while (size > 0)
	{
		temp = stack;
		max_node = NULL;
		while (temp)
		{
			if (temp->main_index == 0)
			{
				if (!max_node || temp->num > max_node->num)
					max_node = temp;
			}
			temp = temp->next;
		}
		if (max_node)
			max_node->main_index = size;
		size--;
	}
}

int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

static t_stack	*ft_ps_lstnew(int num)
{
	t_stack	*stack;

	stack = (t_stack *)safealloc(1, sizeof(t_stack), 0);
	stack->num = num;
	stack->pos = -1;
	stack->target = -1;
	stack->mv_a = -1;
	stack->mv_b = -1;
	return (stack);
}

static void	ft_ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*s;

	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		s = *stack;
		while (s->next)
			s = s->next;
		s->next = new;
	}
}

t_stack	*create_stack(char **av)
{
	t_stack		*stack_a;
	long int	num;
	int			index;

	stack_a = NULL;
	index = 0;
	while (av[index])
	{
		num = ft_atol(av[index]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free_safealloc();
			put_error(av);
		}
		if (index == 0)
			stack_a = ft_ps_lstnew((int)num);
		else
			ft_ps_lstadd_back(&stack_a, ft_ps_lstnew((int)num));
		index++;
	}
	return (stack_a);
}
