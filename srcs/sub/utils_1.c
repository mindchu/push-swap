/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 03:20:19 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/11 04:19:02 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	calculate_moves(t_stack **sa, t_stack **sb)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	a = *sa;
	b = *sb;
	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (b)
	{
		b->mv_b = b->pos;
		if (b->pos > size_b / 2)
			b->mv_b = (size_b - b->pos) * -1;
		b->mv_a = b->target;
		if (b->target > size_a / 2)
			b->mv_a = (size_a - b->target) * -1;
		b = b->next;
	}
}

int	get_a_pos(t_stack **sa, int b_index, int max, int a_pos)
{
	t_stack	*a;

	a = *sa;
	while (a)
	{
		if (a->main_index > b_index && a->main_index < max)
		{
			max = a->main_index;
			a_pos = a->pos;
		}
		a = a->next;
	}
	if (max != INT_MAX)
		return (a_pos);
	a = *sa;
	while (a)
	{
		if (a->main_index < max)
		{
			max = a->main_index;
			a_pos = a->pos;
		}
		a = a->next;
	}
	return (a_pos);
}

void	get_stack_pos(t_stack **st)
{
	t_stack	*s;
	int		i;

	s = *st;
	i = 0;
	while (s)
	{
		s->pos = i;
		s = s->next;
		i++;
	}
}

void	target_in_a(t_stack **sa, t_stack **sb)
{
	t_stack	*b;
	int		a_pos;

	b = *sb;
	get_stack_pos(sa);
	get_stack_pos(sb);
	a_pos = 0;
	while (b)
	{
		a_pos = get_a_pos(sa, b->main_index, INT_MAX, a_pos);
		b->target = a_pos;
		b = b->next;
	}
}
