/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:12:50 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:11:24 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*nl;

	nl = (t_stack *)malloc(sizeof(t_stack));
	if (nl == NULL)
		return (NULL);
	nl->value = value;
	nl->next = NULL;
	return (nl);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst != NULL)
	{
		last = ft_stacklast(*lst);
		last->next = new;
	}
	else
		ft_stackadd_front(lst, new);
}
