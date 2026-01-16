/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:11:13 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 13:17:27 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_atoi_ovrflw(const char *nptr, char **stack_list, t_stacks *stacks)
{
	int		i;
	long	n;
	int		m;

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
	if (nptr[i])
		return (exit_safe(stack_list, stacks, EXIT_FAILURE));
	return (n * m);
}

int	check_duplicates(t_stacks *stacks)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		current_value;

	stack = stacks->a;
	while (stack)
	{
		tmp = stack->next;
		current_value = stack->value;
		while (tmp)
		{
			if (tmp->value == current_value)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
