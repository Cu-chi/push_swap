/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_language_sp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:01:51 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 09:18:54 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_stack	*new_first;

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	new_first = stacks->a->next;
	if (new_first->next)
		new_first->next->prev = stacks->a;
	stacks->a->next = new_first->next;
	new_first->next = stacks->a;
	stacks->a->prev = new_first;
	new_first->prev = NULL;
	stacks->a = new_first;
}

void	sb(t_stacks *stacks)
{
	t_stack	*new_first;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	new_first = stacks->b->next;
	if (new_first->next)
		new_first->next->prev = stacks->b;
	stacks->b->next = new_first->next;
	new_first->next = stacks->b;
	stacks->b->prev = new_first;
	new_first->prev = NULL;
	stacks->b = new_first;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	t_stack	*b;
	t_stack	*a;

	b = stacks->b;
	if (b == NULL)
		return ;
	a = stacks->a;
	if (b->next)
		b->next->prev = NULL;
	stacks->b = b->next;
	b->next = a;
	if (a)
		a->prev = b;
	stacks->a = b;
}

void	pb(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	if (a == NULL)
		return ;
	b = stacks->b;
	if (a->next)
		a->next->prev = NULL;
	stacks->a = a->next;
	a->next = b;
	if (b)
		b->prev = a;
	stacks->b = a;
}
