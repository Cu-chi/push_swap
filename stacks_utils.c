/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:57:44 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 17:11:12 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->nb_values = 0;
	stacks->sa = 0;
	stacks->sb = 0;
	stacks->ss = 0;
	stacks->pa = 0;
	stacks->pb = 0;
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
	stacks->disorder = 0.f;
}

void	free_stacks(t_stacks *stacks)
{
	t_stack	*current;
	t_stack	*next;

	current = stacks->a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stacks->a = NULL;
	current = stacks->b;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stacks->b = NULL;
	stacks = NULL;
}

void	print_stacks(t_stacks stacks)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = stacks.a;
	current_b = stacks.b;
	ft_printf(1, "STACK A:\n");
	while (current_a != NULL)
	{
		ft_printf(1, "%d\n", current_a->value);
		current_a = current_a->next;
	}
	ft_printf(1, "STACK B:\n");
	while (current_b != NULL)
	{
		ft_printf(1, "%d\n", current_b->value);
		current_b = current_b->next;
	}
}

int	create_stack_node(char *str_value, char **stack_list, t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = ft_stacknew(ft_atoi_ovrflw(str_value, stack_list, stacks));
	if (!tmp)
		return (exit_safe(stack_list, stacks, NULL, EXIT_FAILURE));
	ft_stackadd_back(&stacks->a, tmp);
	stacks->nb_values++;
	return (1);
}

int	is_stack_sorted(t_stacks stacks)
{
	t_stack	*current;

	if (stacks.b != NULL)
		return (0);
	current = stacks.a;
	while (current)
	{
		if (current->next)
			if (current->value >= current->next->value)
				return (0);
		current = current->next;
	}
	return (1);
}
