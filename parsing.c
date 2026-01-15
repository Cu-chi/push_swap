/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpietrza <cpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:27:05 by cpietrza          #+#    #+#             */
/*   Updated: 2026/01/15 21:58:29 by cpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stacks(char *res, t_stacks *stacks, int counter)
{
	char	**stack_list;

	stack_list = ft_split(res, ' ');
	if (!stack_list)
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
		exit_safe(NULL, stacks, EXIT_FAILURE);
		return ;
	}
}
void	action_parse(int ac, char **av, int counter, char **res)
{
	char	*tmp;

	tmp = *res;
	*res = ft_strjoin(*res, av[counter]);
	free(tmp);
	if (counter != ac - 1)
	{
		tmp = *res;
		*res = ft_strjoin(tmp, " ");
		free(tmp);
	}
	counter++;
}
char	*parse(int ac, char **av, int counter, t_stacks *stacks)
{
	char	*res;
	int		check;

	check = counter;
	res = ft_strdup("");
	if (!res)
	{
		exit_safe(NULL, stacks, EXIT_FAILURE);
		return (NULL);
	}
	while (counter < ac)
	{
		check_parse(av, res, stacks, counter);
		action_parse(ac, av, counter, &res);
		counter++;
	}
	if (!create_stacks(res, stacks, 0))
	{
		free(res);
		exit_safe(NULL, stacks, EXIT_FAILURE);
		return (NULL);
	}
	return (res);
}
