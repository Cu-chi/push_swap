/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:13:27 by equentin          #+#    #+#             */
/*   Updated: 2026/01/14 11:12:29 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit_at(int value, int bit_pos)
{
	int r;

	r = 0;
	while (value > 0 && bit_pos-- >= 0)
	{
		r = value % 2;
		value /= 2;
	}
	if (value == 0 && bit_pos >= 0)
		return (0);
	return (r);
}

int	get_bin_len(int value)
{
	int len;

	len = 0;
	while (value > 0)
	{
		len++;
		value /= 2;
	}
	return (len);
}

int	find_index(int value, int *sorted, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->nb_values)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	lsd_radix_sort(t_stacks *stacks)
{
	int		*sorted;
	int		values_checked;
	int		bit_pos;
	int		bit;
	int		max_bit_len;

	sorted = preprocess_values(stacks);
	bit_pos = 0;
	max_bit_len = get_bin_len(stacks->nb_values);
	while (max_bit_len--)
	{
		values_checked = 0;
		while (values_checked++ < stacks->nb_values)
		{
			bit = get_bit_at(find_index(stacks->a->value, sorted, stacks), bit_pos);
			if (bit == 0)
				pb(stacks);
			else
				ra(stacks, 0);
		}
		while (stacks->b)
			pa(stacks);
		bit_pos++;
	}
	free(sorted);
}
