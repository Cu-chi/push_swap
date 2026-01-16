/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:57:44 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 13:35:09 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	init_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
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

int	create_stack_node(char *str_value, char **stack_list, t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = ft_stacknew(ft_atoi_ovrflw(str_value, stack_list, stacks));
	if (!tmp)
		return (exit_safe(stack_list, stacks, EXIT_FAILURE));
	ft_stackadd_back(&stacks->a, tmp);
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
