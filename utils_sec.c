/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:30:11 by equentin          #+#    #+#             */
/*   Updated: 2026/01/15 14:07:17 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
