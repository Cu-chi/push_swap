/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:27:03 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:53 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	ft_itoa_u_size(unsigned int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*a;
	int		size;

	size = ft_itoa_u_size(n);
	a = (char *)ft_calloc(size + 1, sizeof(char));
	if (a == NULL)
		return (NULL);
	while (n >= 0 && size > 0)
	{
		size--;
		a[size] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
