/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:48:46 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:21:00 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stackprevlast(t_stack *stack)
{
	int		size;
	t_stack	*prevlast;

	prevlast = stack;
	size = ft_stacksize(stack);
	while (size-- > 2)
		prevlast = prevlast->next;
	return (prevlast);
}

void	rra(t_stacks *stacks, char rrr)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

	if (!rrr)
	{
		stacks->rra++;
		ft_printf(1, "rra\n");
	}
	first = stacks->a;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	prev_last = ft_stackprevlast(first);
	prev_last->next = NULL;
	last->next = first;
	stacks->a = last;
}

void	rrb(t_stacks *stacks, char rrr)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

	if (!rrr)
	{
		stacks->rrb++;
		ft_printf(1, "rrb\n");
	}
	first = stacks->b;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	prev_last = ft_stackprevlast(first);
	prev_last->next = NULL;
	last->next = first;
	stacks->b = last;
}

void	rrr(t_stacks *stacks)
{
	stacks->rrr++;
	ft_printf(1, "rrr\n");
	rra(stacks, 1);
	rrb(stacks, 1);
}
