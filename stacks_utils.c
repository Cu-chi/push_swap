/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:57:44 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 09:37:30 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	char	*itoa;

	current_a = stacks.a;
	current_b = stacks.b;
	ft_printf("STACK A:\n");
	while (current_a != NULL)
	{
		if (current_a->prev)
			ft_printf("%d (prev is %d)\n", current_a->value,
				current_a->prev->value);
		else
			ft_printf("%d\n", current_a->value);
		current_a = current_a->next;
	}
	ft_printf("STACK B:\n");
	while (current_b != NULL)
	{
		if (current_b->prev)
			ft_printf("%d (prev is %d)\n", current_b->value,
				current_b->prev->value);
		else
			ft_printf("%d\n", current_b->value);
		current_b = current_b->next;
	}
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
