/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:27:05 by cpietrza          #+#    #+#             */
/*   Updated: 2026/01/23 16:47:31 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(char *res, t_stacks *stacks, int counter)
{
	char	**stack_list;

	stack_list = ft_split(res, ' ');
	free(res);
	if (!stack_list || !stack_list[0])
		return (0);
	counter = 0;
	while (stack_list[counter])
	{
		if (!create_stack_node(stack_list[counter++], stack_list, stacks))
		{
			free_stack_list(stack_list);
			return (0);
		}
	}
	free_stack_list(stack_list);
	if (check_duplicates(stacks))
		return (0);
	return (1);
}

void	check_parse(char **av, char *res, t_stacks *stacks, int counter)
{
	if (*av[counter] == '\0')
	{
		free(res);
		exit_safe(NULL, stacks, NULL, EXIT_FAILURE);
	}
}

void	action_parse(int is_last, char *arg, char **res, t_stacks *stacks)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, arg);
	free(tmp);
	if (!*res)
		exit_safe(NULL, stacks, NULL, EXIT_FAILURE);
	if (!is_last)
	{
		tmp = *res;
		*res = ft_strjoin(tmp, " ");
		free(tmp);
		if (!*res)
			exit_safe(NULL, stacks, NULL, EXIT_FAILURE);
	}
}

void	parse(int ac, char **av, int counter, t_stacks *stacks)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		exit_safe(NULL, stacks, NULL, EXIT_FAILURE);
	while (counter < ac)
	{
		check_parse(av, res, stacks, counter);
		action_parse(!(counter - ac - 1), av[counter], &res, stacks);
		counter++;
	}
	if (!create_stacks(res, stacks, 0))
		exit_safe(NULL, stacks, NULL, EXIT_FAILURE);
}
