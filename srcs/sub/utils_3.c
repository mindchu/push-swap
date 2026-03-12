/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chutterm <chutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 05:01:25 by chutterm          #+#    #+#             */
/*   Updated: 2026/03/13 02:30:25 by chutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	put_error(char **args)
{
	if (args)
		free_matrix(args);
	free_safealloc();
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	*join_args(int ac, char **av)
{
	char	*joined_str;
	char	*temp1;
	char	*temp2;
	int		i;

	joined_str = ft_strdup("");
	if (!joined_str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		temp1 = ft_strjoin(joined_str, av[i]);
		free(joined_str);
		temp2 = ft_strjoin(temp1, " ");
		free(temp1);
		joined_str = temp2;
		i++;
	}
	return (joined_str);
}
