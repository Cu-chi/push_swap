/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:01:51 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:11:40 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stacks *stacks)
{
	t_stack	*new_first;

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	new_first = stacks->a->next;
	stacks->a->next = new_first->next;
	new_first->next = stacks->a;
	stacks->a = new_first;
}

void	sb(t_stacks *stacks)
{
	t_stack	*new_first;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	new_first = stacks->b->next;
	stacks->b->next = new_first->next;
	new_first->next = stacks->b;
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
	stacks->b = b->next;
	b->next = a;
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
	stacks->a = a->next;
	a->next = b;
	stacks->b = a;
}
