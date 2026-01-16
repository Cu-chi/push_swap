/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:54:57 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 08:55:22 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	max;
	int	tmp;
	int	i;

	while (size > 0)
	{
		size--;
		i = 0;
		max = 0;
		while (i <= size)
		{
			if (tab[i] > tab[max])
				max = i;
			i++;
		}
		tmp = tab[max];
		tab[max] = tab[size];
		tab[size] = tmp;
	}
}

void	populate_tab(int *tab, t_stacks *stacks)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = stacks->a;
	while (stack)
	{
		tab[i++] = stack->value;
		stack = stack->next;
	}
}

int	*preprocess_values(t_stacks *stacks)
{
	int	*tab;
	int	size;
	int	i;

	size = stacks->nb_values;
	tab = malloc(sizeof(int) * size);
	i = 0;
	if (!tab)
	{
		exit_safe(NULL, stacks, NULL, EXIT_FAILURE);
		return (NULL);
	}
	populate_tab(tab, stacks);
	sort_tab(tab, size);
	return (tab);
}
