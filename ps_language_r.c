/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_language_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:52:48 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 11:06:33 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, char rr)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!rr)
		stacks->ra++;
	first = stacks->a;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	second = first->next;
	second->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	stacks->a = second;
}

void	rb(t_stacks *stacks, char rr)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!rr)
		stacks->rb++;
	first = stacks->b;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	second = first->next;
	second->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	stacks->b = second;
}

void	rr(t_stacks *stacks)
{
	stacks->rr++;
	ra(stacks, 1);
	rb(stacks, 1);
}
