/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:30:20 by equentin          #+#    #+#             */
/*   Updated: 2026/01/15 11:23:50 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *stack)
{
	int	index;
	int	counter;
	int	min_value;

	index = -1;
	counter = 0;
	min_value = 0;
	while (stack)
	{
		if (index == -1 || stack->value < min_value)
		{
			min_value = stack->value;
			index = counter;
		}
		stack = stack->next;
		counter++;
	}
	return (index);
}

void	selection_sort(t_stacks *stacks)
{
	int		min_index;
	int		reverse;

	while (stacks->a)
	{
		min_index = get_min_index(stacks->a);
		reverse = min_index > stacks->nb_values / 2;
		while (min_index > 0)
		{
			if (reverse)
				rra(stacks, 0);
			else
				ra(stacks, 0);
			min_index = get_min_index(stacks->a);
		}
		pb(stacks);
	}
	while (stacks->b)
		pa(stacks);
}
