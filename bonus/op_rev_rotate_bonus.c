/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:48:46 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:20:51 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_stackprevlast(t_stack *stack)
{
	int		size;
	t_stack	*prevlast;

	prevlast = stack;
	size = ft_stacksize(stack);
	while (size-- > 1)
		prevlast = prevlast->next;
	return (prevlast);
}

void	rra(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*prev_last;
	t_stack	*last;

	first = stacks->a;
	last = ft_stacklast(first);
	if (first == last)
		return ;
	prev_last = ft_stackprevlast(first);
	prev_last->next = NULL;
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
	prev_last = ft_stackprevlast(first);
	prev_last->next = NULL;
	last->next = first;
	stacks->b = last;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
