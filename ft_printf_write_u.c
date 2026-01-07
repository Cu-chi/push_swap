/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:13:02 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:39 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	write_u(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	char			*a;
	unsigned int	u;
	unsigned int	len;

	u = va_arg(*ap, unsigned);
	if (u == 0 && fmt_lst->has_prs && (unsigned int)fmt_lst->precision == 0)
		return (only_format(fmt_lst, printed));
	a = ft_itoa_u(u);
	len = ft_strlen(a);
	if (fmt_lst->precision && (unsigned int)fmt_lst->precision > len)
		format_pre_conv(fmt_lst, printed, len + (fmt_lst->precision - len));
	else
		format_pre_conv(fmt_lst, printed, len);
	precision(fmt_lst, printed, len);
	ft_putstr_fd(a, 1);
	*printed += len;
	free(a);
	if (fmt_lst->precision && (unsigned int)fmt_lst->precision > len)
		format_post_conv(fmt_lst, printed, len + (fmt_lst->precision - len));
	else
		format_post_conv(fmt_lst, printed, len);
}
