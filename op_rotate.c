/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:52:48 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:10:53 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, char rr)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!rr)
	{
		stacks->ra++;
		ft_printf(1, "ra\n");
	}
	first = stacks->a;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	second = first->next;
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
	{
		stacks->rb++;
		ft_printf(1, "rb\n");
	}
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
	stacks->rr++;
	ft_printf(1, "rr\n");
	ra(stacks, 1);
	rb(stacks, 1);
}
