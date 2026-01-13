/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:34:59 by equentin          #+#    #+#             */
/*   Updated: 2026/01/13 17:27:17 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk(int n, t_stacks *stacks, int range, int *sorted)
{
	int	n_index;
	int	i;
	int	chunk;

	n_index = -1;
	i = 0;
	while (n_index < 0 && i < stacks->nb_values)
	{
		if (sorted[i] == n)
			n_index = i;
		i++;
	}
	return (n_index / range);
}

void	sort_chunk(t_stacks *stacks, int sorting_chunk, int range, int *sorted)
{
	int	nb_chunk;
	int	current_chunk;
	int	nb_sorted;

	nb_sorted = 0;
	nb_chunk = ft_sqrt(stacks->nb_values);
	while (nb_sorted < range)
	{
		current_chunk = get_chunk(stacks->a->value, stacks, range, sorted);
		if (current_chunk >= nb_chunk)
			current_chunk--;
		if (current_chunk == sorting_chunk)
		{
			pb(stacks);
			nb_sorted++;
		}
		else
			ra(stacks, 0);
	}
}

int	get_max_index_range(t_stack *stack)
{
	int	index;
	int	counter;
	int	max_value;

	index = -1;
	counter = 0;
	max_value = 0;
	while (stack)
	{
		if (index == -1 || stack->value > max_value)
		{
			max_value = stack->value;
			index = counter;
		}
		stack = stack->next;
		counter++;
	}
	return (index);
}

void	process_operations(t_stacks *stacks, int range)
{
	int max_index;

	max_index = get_max_index_range(stacks->b);
	while (max_index > 0)
	{
		if (max_index == 1)
			sb(stacks, 0);
		else if (max_index >= range)
			rrb(stacks, 0);
		else
			rb(stacks, 0);
		max_index = get_max_index_range(stacks->b);
	}
	pa(stacks);
}

void	chunk_based_sort(t_stacks *stacks)
{
	int	*sorted;
	int	nb_chunk;
	int	range;
	int	i;

	sorted = preprocess_values(stacks);
	nb_chunk = ft_sqrt(stacks->nb_values);
	range = stacks->nb_values / nb_chunk;
	i = 0;
	while (i < nb_chunk)
		sort_chunk(stacks, i++, range, sorted);
	while (stacks->b)
		process_operations(stacks, range);
	free(sorted);
}
