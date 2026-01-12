/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:11:13 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 11:57:52 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_list(char **stack_list)
{
	int	i;

	i = 0;
	while (stack_list[i] != NULL)
		free(stack_list[i++]);
	free(stack_list);
}

int	exit_safe(char **stack_list, t_stacks *stacks, int fail)
{
	if (stack_list)
		free_stack_list(stack_list);
	free_stacks(stacks);
	ft_printf(2, "Error\n");
	exit(fail);
	return (0);
}

int	ft_atoi_ovrflw(const char *nptr, char **stack_list, t_stacks *stacks)
{
	int				i;
	unsigned int	n;
	int				m;

	i = 0;
	n = 0;
	m = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			m = -1;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (exit_safe(stack_list, stacks, EXIT_FAILURE));
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i++] - '0';
		if ((m == 1 && n > 2147483647) || (m == -1 && n > 2147483648))
			return (exit_safe(stack_list, stacks, EXIT_FAILURE));
	}
	return (n * m);
}

int	check_duplicates(t_stacks *stacks)
{
	t_stack *stack;
	t_stack *tmp;
	int	current_value;

	stack = stacks->a;
	tmp = stacks->a;
	if (stack == NULL)
		return (0);
	current_value = stack->value;
	while (stack)
	{
		while (tmp)
		{
			tmp = tmp->next;
			if (tmp && tmp->value == current_value)
				return (1);
		}
		stack = stack->next;
	}
	return (0);
}
