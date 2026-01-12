/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:37:10 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 10:19:06 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(int ac, char **av, t_stacks *stacks, int counter)
{
	char	**stack_list;
	t_stack	*tmp;
	t_stack	*prev;

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

int	main(int ac, char **av)
{
	t_arguments	args;
	t_stack		stack_a;
	t_stack		stack_b;
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (args_checker(ac, av, &args, &stacks) == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	print_stacks(stacks);
	sa(&stacks);
	ft_printf("---------------------------\nExec sa\n");
	print_stacks(stacks);
	pb(&stacks);
	pb(&stacks);
	pb(&stacks);
	ft_printf("---------------------------\nExec pb pb pb\n");
	print_stacks(stacks);
	ra(&stacks);
	rb(&stacks);
	ft_printf("---------------------------\nExec ra rb\n");
	print_stacks(stacks);
	rra(&stacks);
	rrb(&stacks);
	ft_printf("---------------------------\nExec rra rrb\n");
	print_stacks(stacks);
	sa(&stacks);
	ft_printf("---------------------------\nExec sa\n");
	print_stacks(stacks);
	pa(&stacks);
	pa(&stacks);
	pa(&stacks);
	ft_printf("---------------------------\nExec pa pa pa\n");
	print_stacks(stacks);
	ft_printf("STACK A SORTED?: %d", is_stack_sorted(stacks));
	free_stacks(&stacks);
	return (0);
}
