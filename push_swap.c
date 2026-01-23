/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpietrza <cpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:37:10 by equentin          #+#    #+#             */
/*   Updated: 2026/01/23 11:13:24 by cpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ch_dble(t_arguments *args, char c)
{
	if (c == 'b' && !args->bench)
		return (0);
	else if (c != 'b' && !args->simple && !args->medium && !args->complex
		&& !args->adaptive)
		return (0);
	return (1);
}

int	args_checker(int ac, char **av, t_arguments *args, t_stacks *stacks)
{
	int	ctn;

	ctn = 1;
	while (ctn < ac && av[ctn][0] == '-' && av[ctn][1] == '-')
	{
		if (!ch_dble(args, 'b') && !ft_strncmp(av[ctn], "--bench", 8))
			args->bench = 1;
		else if (!ch_dble(args, 's') && !ft_strncmp(av[ctn],
				"--simple", 9))
			args->simple = 1;
		else if (!ch_dble(args, 'm') && !ft_strncmp(av[ctn],
				"--medium", 9))
			args->medium = 1;
		else if (!ch_dble(args, 'c') && !ft_strncmp(av[ctn],
				"--complex", 10))
			args->complex = 1;
		else if (!ch_dble(args, 'a') && !ft_strncmp(av[ctn],
				"--adaptive", 11))
			args->adaptive = 1;
		else
			return (0);
		ctn++;
	}
	parse(ac, av, ctn, stacks);
	return (1);
}

void	benchmark(t_arguments args, t_stacks stacks)
{
	int	total_ops;

	total_ops = 0;
	total_ops += stacks.sa;
	total_ops += stacks.sb;
	total_ops += stacks.ss;
	total_ops += stacks.pa;
	total_ops += stacks.pb;
	total_ops += stacks.ra;
	total_ops += stacks.rb;
	total_ops += stacks.rr;
	total_ops += stacks.rra;
	total_ops += stacks.rrb;
	total_ops += stacks.rrr;
	ft_printf(2, "[bench] %-10s %d.%d%%\n", "disorder:", (int)(stacks.disorder
			* 100), (int)(stacks.disorder * 10000) % 100);
	ft_printf(2, "[bench] %-10s %s\n", "strategy:", benchmark_strategy(args,
			stacks));
	ft_printf(2, "[bench] %-10s %d\n", "total_ops:", total_ops);
	ft_printf(2, "[bench] %-4s %-5d %-4s %-5d %-4s %-5d %-4s %-5d %-4s %5d\n",
		"sa:", stacks.sa, "sb:", stacks.sb, "ss:", stacks.ss, "pa:", stacks.pa,
		"pb:", stacks.pb);
	ft_printf(2, "[bench] %-4s %-5d %-4s %-5d %-4s %-5d %-4s %-5d %-4s %5d\n",
		"ra:", stacks.ra, "rb:", stacks.rb, "rr:", stacks.rr, "rra:",
		stacks.rra, "rrb:", stacks.rrb, "rrr:", stacks.rrr);
}

void	init_args(t_arguments *args)
{
	args->bench = 0;
	args->simple = 0;
	args->medium = 0;
	args->complex = 0;
	args->adaptive = 0;
}

int	main(int ac, char **av)
{
	t_arguments	args;
	t_stacks	stacks;

	if (ac == 1)
		return (0);
	init_args(&args);
	init_stacks(&stacks);
	if (args_checker(ac, av, &args, &stacks) == 0)
		return (exit_safe(NULL, &stacks, NULL, EXIT_FAILURE));
	if (is_stack_sorted(stacks))
		return (exit_safe(NULL, &stacks, &args, EXIT_SUCCESS));
	stacks.disorder = compute_disorder(&stacks);
	if (args.simple || (stacks.disorder < 0.2f && !args.medium
			&& !args.complex))
		selection_sort(&stacks);
	else if (args.medium || (stacks.disorder >= 0.2f && stacks.disorder < 0.5f
			&& !args.complex))
		chunk_based_sort(&stacks);
	else if (args.complex || stacks.disorder >= 0.5f)
		lsb_radix_sort(&stacks);
	return (exit_safe(NULL, &stacks, &args, EXIT_SUCCESS));
}
