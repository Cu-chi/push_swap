/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:30:11 by equentin          #+#    #+#             */
/*   Updated: 2026/01/15 14:18:27 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_list(char **stack_list)
{
	int	i;

	i = 0;
	while (stack_list[i] != NULL)
		free(stack_list[i++]);
	free(stack_list);
}

int	exit_safe(char **stack_list, t_stacks *stacks, int fail)
{
	if (stack_list)
		free_stack_list(stack_list);
	free_stacks(stacks);
	ft_printf(2, "Error\n");
	exit(fail);
	return (fail);
}
