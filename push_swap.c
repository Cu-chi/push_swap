/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:37:10 by equentin          #+#    #+#             */
/*   Updated: 2026/01/15 11:25:52 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(int ac, char **av, t_stacks *stacks, int counter)
{
	char	**stack_list;

	stack_list = NULL;
	if (counter + 1 == ac)
	{
		stack_list = ft_split(av[counter], ' ');
		if (!stack_list)
			return (0);
		counter = 0;
	}
	if (stack_list)
	{
		while (stack_list[counter])
			create_stack_node(stack_list[counter++], stack_list, stacks);
		free_stack_list(stack_list);
		return (1);
	}
	while (counter < ac && av[counter])
		create_stack_node(av[counter++], stack_list, stacks);
	if (check_duplicates(stacks))
		return (0);
	return (1);
}

int	args_checker(int ac, char **av, t_arguments *args, t_stacks *stacks)
{
	int	counter;

	if (ac <= 1)
		return (0);
	counter = 1;
	while (counter < ac && av[counter][0] == '-')
	{
		if (av[counter][1] != '-')
			break ;
		if (ft_strncmp(av[counter], "--bench", 8) == 0)
			args->bench = 1;
		else if (ft_strncmp(av[counter], "--simple", 9) == 0)
			args->simple = 1;
		else if (ft_strncmp(av[counter], "--medium", 9) == 0)
			args->medium = 1;
		else if (ft_strncmp(av[counter], "--complex", 10) == 0)
			args->complex = 1;
		else if (ft_strncmp(av[counter], "--adaptive", 11) == 0)
			args->adaptive = 1;
		else
			return (0);
		counter++;
	}
	return (create_stacks(ac, av, stacks, counter));
}

void	benchmark(t_stacks stacks)
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
	ft_printf(2, "[bench] %-10s %d%%\n", "disorder:", 0);
	ft_printf(2, "[bench] %-10s %s\n", "strategy:", "TODO / O(TODO)");
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

	init_args(&args);
	init_stacks(&stacks);
	if (args_checker(ac, av, &args, &stacks) == 0)
		return (exit_safe(NULL, &stacks, EXIT_FAILURE));
	if (is_stack_sorted(stacks))
		return (0);
	if (args.simple)
		selection_sort(&stacks);
	else if (args.medium)
		chunk_based_sort(&stacks);
	else if (args.complex)
		lsb_radix_sort(&stacks);
	if (args.bench)
		benchmark(stacks);
	// run_benchmark(&lsd_radix_sort);
	free_stacks(&stacks);
	return (0);
}
