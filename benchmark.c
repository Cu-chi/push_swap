/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:08:11 by equentin          #+#    #+#             */
/*   Updated: 2026/01/15 12:35:14 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BENCH
# include "push_swap.h"
# include <stdio.h>
# define STACK_SIZE_STR "500"
# define STACK_SIZE 500
# define BENCHMARK_NB 1000

int	get_total_ops(t_stacks stacks)
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
	return (total_ops);
}

char	**generate_random_stack(void)
{
	FILE	*fp;
	char	path[8];
	char	*cmd;
	char	**stack;
	int		i;

	i = 0;
	cmd = ft_strjoin("shuf -i 0-9999 -n ", STACK_SIZE_STR);
	stack = malloc(sizeof(char *) * STACK_SIZE);
	fp = popen(cmd, "r");
	while (fgets(path, sizeof(path), fp) != NULL)
		stack[i++] = ft_strdup(path);
	pclose(fp);
	return (stack);
}

void	run_benchmark(void algorithm(t_stacks *))
{
	t_stacks	stacks;
	t_arguments	args;
	int			average_ops;
	int			i;
	char		**stack_str;

	i = 0;
	average_ops = 0;
	while (i++ < BENCHMARK_NB)
	{
		stack_str = generate_random_stack();
		init_stacks(&stacks);
		args_checker(STACK_SIZE + 1, stack_str, &args, &stacks);
		algorithm(&stacks);
		average_ops += get_total_ops(stacks);
		ft_printf(2, "got %d for %d/%d\n", get_total_ops(stacks), i,
			BENCHMARK_NB);
	}
	average_ops /= BENCHMARK_NB;
	ft_printf(2, "[FULL BENCHMARK] Average operations (on %d runs)",
		BENCHMARK_NB);
	ft_printf(2, " with a stack of %s elements: %d\n", STACK_SIZE_STR,
		average_ops);
}
#endif
