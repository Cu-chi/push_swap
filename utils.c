/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:11:13 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 08:48:52 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		return (0);
	while (i * i <= n && i <= 46340)
		i++;
	return (i - 1);
}

float	compute_disorder(t_stacks *stacks)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*current;
	t_stack	*checking;

	mistakes = 0;
	total_pairs = 0;
	current = stacks->a;
	while (current)
	{
		checking = current->next;
		while (checking)
		{
			total_pairs++;
			if (current->value > checking->value)
				mistakes++;
			checking = checking->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.f);
	return (mistakes / total_pairs);
}

char	*benchmark_strategy(t_arguments args, t_stacks stacks)
{
	if (args.simple)
		return ("Simple / O(n²)");
	else if (args.medium)
		return ("Medium / O(n√n)");
	else if (args.complex)
		return ("Complex / O(n log n)");
	if (stacks.disorder < 0.2f)
		return ("Adaptative / O(n²)");
	else if (stacks.disorder >= 0.2f && stacks.disorder < 0.5f)
		return ("Adaptative / O(n√n)");
	else
		return ("Adaptative / O(n log n)");
}
