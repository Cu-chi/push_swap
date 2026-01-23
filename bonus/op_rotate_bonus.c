/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:52:48 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:14:22 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = stacks->a;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	second = first->next;
	first->next = NULL;
	last->next = first;
	stacks->a = second;
}

void	rb(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = stacks->b;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	second = first->next;
	first->next = NULL;
	last->next = first;
	stacks->b = second;
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
