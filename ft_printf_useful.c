/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:12:58 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:27 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	only_format(t_format_list *fmt_lst, int *printed)
{
	format_pre_conv(fmt_lst, printed, 0);
	format_post_conv(fmt_lst, printed, 0);
}

int	count_digits_base(size_t nb, int base)
{
	int	c;

	c = 1;
	while (nb >= (size_t)base)
	{
		nb /= base;
		c++;
	}
	return (c);
}
