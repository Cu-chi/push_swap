/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:01:51 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:10:43 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, char ss)
{
	t_stack	*new_first;

	if (!ss)
	{
		stacks->sa++;
		ft_printf(1, "sa\n");
	}
	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	new_first = stacks->a->next;
	stacks->a->next = new_first->next;
	new_first->next = stacks->a;
	stacks->a = new_first;
}

void	sb(t_stacks *stacks, char ss)
{
	t_stack	*new_first;

	if (!ss)
	{
		stacks->sb++;
		ft_printf(1, "sb\n");
	}
	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	new_first = stacks->b->next;
	stacks->b->next = new_first->next;
	new_first->next = stacks->b;
	stacks->b = new_first;
}

void	ss(t_stacks *stacks)
{
	stacks->ss++;
	ft_printf(1, "ss\n");
	sa(stacks, 1);
	sb(stacks, 1);
}

void	pa(t_stacks *stacks)
{
	t_stack	*b;
	t_stack	*a;

	stacks->pa++;
	ft_printf(1, "pa\n");
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

	stacks->pb++;
	ft_printf(1, "pb\n");
	a = stacks->a;
	if (a == NULL)
		return ;
	b = stacks->b;
	stacks->a = a->next;
	a->next = b;
	stacks->b = a;
}
