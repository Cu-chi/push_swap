/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:13:27 by equentin          #+#    #+#             */
/*   Updated: 2026/01/13 18:29:48 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
	int		bit_pos;
	int		bit;

	sorted = preprocess_values(stacks);
	bit_pos = 0;
	while (!is_stack_sorted(*stacks))
	{
		i = 0;
		//ft_printf(2, "taille stack a: %d\n", ft_stacksize(stacks->a));
		while (i++ < stacks->nb_values)
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
