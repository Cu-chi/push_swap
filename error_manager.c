/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:30:11 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 08:59:27 by equentin         ###   ########.fr       */
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

int	exit_safe(char **stack_list, t_stacks *stacks, t_arguments *args, int fail)
{
	if (stack_list)
		free_stack_list(stack_list);
	if (fail)
		ft_printf(2, "Error\n");
	else if (args->bench)
		benchmark(*args, *stacks);
	free_stacks(stacks);
	exit(fail);
	return (fail);
}
