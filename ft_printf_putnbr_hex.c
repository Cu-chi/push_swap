/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:13:48 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 11:15:58 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long nbr, char *base, int *printed, int fd)
{
	if (nbr < 16)
	{
		write(fd, base + nbr % 16, 1);
		(*printed)++;
		return ;
	}
	ft_putnbr_hex(nbr / 16, base, printed, fd);
	ft_putnbr_hex(nbr % 16, base, printed, fd);
}
