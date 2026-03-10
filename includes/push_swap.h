/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:59:09 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/11 05:21:02 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libsafealloc.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line_bonus.h"

typedef struct s_stack
{
	int				num;
	int				main_index;
	int				pos;
	int				target;
	int				mv_a;
	int				mv_b;
	struct s_stack	*next;
}	t_stack;

int			check_input(char **arg);
int			get_stack_size(t_stack *st);
t_stack		*create_stack(int ac, char **av);
void		get_main_index(t_stack *sa, int size);
int			is_sorted(t_stack *st);

void		swap_move(t_stack **sa, t_stack **sb, char *choice);
void		small_sort(t_stack **st);
void		rotate_move(t_stack **sa, t_stack **sb, char *choice);
void		big_sort(t_stack **sa, t_stack **sb);

void		less_moves_sort(t_stack **sa, t_stack **sb);
int			get_lower_pos(t_stack **st);
void		target_in_a(t_stack **sa, t_stack **sb);
void		get_stack_pos(t_stack **st);
void		calculate_moves(t_stack **sa, t_stack **sb);

int			ft_strcmp(char *s1, char *s2);
int			absolute(int n);
void		put_error(void);
long    	ft_atol(const char *str);

#endif