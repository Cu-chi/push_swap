/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:48:46 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 13:40:12 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

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

void	rrb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

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
	rra(stacks);
	rrb(stacks);
}
