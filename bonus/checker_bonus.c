/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:56:51 by equentin          #+#    #+#             */
/*   Updated: 2026/01/16 14:28:16 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "checker_bonus.h"

int	exec_instruction(char *instruction, t_stacks *stacks)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(stacks);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(stacks);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(stacks);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(stacks);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(stacks);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(stacks);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(stacks);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(stacks);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(stacks);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(stacks);
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char		*stdin;
	t_stacks	stacks;

	if (ac <= 1)
		return (0);
	init_stacks(&stacks);
	parse(ac, av, 1, &stacks);
	stdin = get_next_line(0);
	while (stdin)
	{
		if (!exec_instruction(stdin, &stacks))
		{
			free(stdin);
			return (exit_safe(NULL, &stacks, EXIT_FAILURE));
		}
		free(stdin);
		stdin = get_next_line(0);
	}
	if (!is_stack_sorted(stacks))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (exit_safe(NULL, &stacks, EXIT_SUCCESS));
}
