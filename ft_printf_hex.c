/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:46:43 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:45 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	format_hex(t_format_list *fmt_lst, int *nb_digit,
		int *printed)
{
	*nb_digit += 2;
	if (!fmt_lst->has_pad && !fmt_lst->has_prs && !fmt_lst->has_lad)
		format_pre_conv(fmt_lst, printed, *nb_digit);
	if (fmt_lst->c == 'x')
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0X", 1);
	*printed += 2;
	if (fmt_lst->has_pad && !fmt_lst->has_prs && !fmt_lst->has_lad)
		format_pre_conv(fmt_lst, printed, *nb_digit);
}

void	write_x(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	const unsigned int	u = va_arg(*ap, unsigned);
	int		nb_digit;

	if (u == 0 && fmt_lst->has_prs && fmt_lst->precision == 0)
		return (only_format(fmt_lst, printed));
	nb_digit = count_digits_base(u, 16);
	if ((unsigned)fmt_lst->precision > nb_digit)
		nb_digit += fmt_lst->precision - nb_digit;
	if (u > 0 && fmt_lst->has_hex)
		format_hex(fmt_lst, &nb_digit, printed);
	else
		format_pre_conv(fmt_lst, printed, nb_digit);
	precision(fmt_lst, printed, count_digits_base(u, 16));
	if (fmt_lst->c == 'x')
		ft_putnbr_hex(u, "0123456789abcdef", printed);
	else
		ft_putnbr_hex(u, "0123456789ABCDEF", printed);
	format_post_conv(fmt_lst, printed, nb_digit);
}
