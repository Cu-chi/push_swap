/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_language_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:48:46 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 11:07:46 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, char rrr)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

	if (!rrr)
		stacks->rra++;
	first = stacks->a;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	prev_last = last->prev;
	prev_last->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	stacks->a = last;
}

void	rrb(t_stacks *stacks, char rrr)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

	if (!rrr)
		stacks->rrb++;
	first = stacks->b;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	prev_last = last->prev;
	prev_last->next = NULL;
	first->prev = last;
	last->prev = NULL;
	last->next = first;
	stacks->b = last;
}

void	rrr(t_stacks *stacks)
{
	stacks->rrr++;
	rra(stacks, 1);
	rrb(stacks, 1);
}
