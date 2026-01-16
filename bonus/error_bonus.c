/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:42:55 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 12:58:22 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	if (fail)
		write(2, "Error\n", 6);
	free_stacks(stacks);
	exit(fail);
	return (fail);
}
