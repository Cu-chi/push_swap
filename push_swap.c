/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:37:10 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 14:49:25 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_checker(int ac, char **av, t_arguments *args)
{
	int	counter;

	if (ac <= 1)
		return (0);
	counter = 1;
	while (av[counter][0] == '-')
	{
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
		counter++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_arguments	args;

	ft_printf("");
	return (0);
}
