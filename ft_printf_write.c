/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:13:02 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 11:16:17 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	write_c(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	const char	c = (char)va_arg(*ap, int);

	format_pre_conv(fmt_lst, printed, 1);
	ft_putchar_fd(c, fmt_lst->fd);
	(*printed)++;
	format_post_conv(fmt_lst, printed, 1);
}

void	write_s(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	char	*s;
	size_t	len;

	s = va_arg(*ap, char *);
	fmt_lst->has_pad = 0;
	if (s == NULL && fmt_lst->has_prs && fmt_lst->precision < 6)
		only_format(fmt_lst, printed);
	else if (s == NULL)
	{
		format_pre_conv(fmt_lst, printed, 6);
		ft_putstr_fd("(null)", fmt_lst->fd);
		*printed += 6;
		format_post_conv(fmt_lst, printed, 6);
	}
	else
	{
		len = ft_strlen(s);
		if (fmt_lst->has_prs && (size_t)fmt_lst->precision < len)
			len = fmt_lst->precision;
		format_pre_conv(fmt_lst, printed, len);
		write(fmt_lst->fd, s, len);
		*printed += len;
		format_post_conv(fmt_lst, printed, len);
	}
}

void	write_p(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	void			*p;
	unsigned int	count;

	p = va_arg(*ap, void *);
	if (!p)
	{
		format_pre_conv(fmt_lst, printed, 5);
		ft_putstr_fd("(nil)", fmt_lst->fd);
		*printed += 5;
		format_post_conv(fmt_lst, printed, 5);
	}
	else
	{
		count = count_digits_base((size_t)p, 16) + 2;
		format_pre_conv(fmt_lst, printed, count);
		fmt_lst->has_hex = 1;
		ft_putstr_fd("0x", fmt_lst->fd);
		*printed += 2;
		ft_putnbr_hex((size_t)p, "0123456789abcdef", printed, fmt_lst->fd);
		format_post_conv(fmt_lst, printed, count);
	}
}

static void	write_sign(t_format_list *fmt_lst, int di)
{
	if (di < 0)
		ft_putchar_fd('-', 1);
	else if (fmt_lst->has_sgn)
		ft_putchar_fd('+', 1);
	else if (fmt_lst->has_blk)
		ft_putchar_fd(' ', 1);
}

void	write_di(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	char		*a;
	const int	di = va_arg(*ap, int);
	size_t		len;

	if (di == 0 && fmt_lst->has_prs && fmt_lst->precision == 0)
		return (only_format(fmt_lst, printed));
	if (di < 0)
		a = ft_itoa_u(-di);
	else
		a = ft_itoa(di);
	len = ft_strlen(a);
	if ((unsigned int)fmt_lst->precision > len)
		len += fmt_lst->precision - len;
	if (fmt_lst->has_prs || !fmt_lst->has_pad)
		format_pre_conv(fmt_lst, printed, len + (di < 0));
	write_sign(fmt_lst, di);
	if (((fmt_lst->has_blk || fmt_lst->has_sgn) && di >= 0) || di < 0)
		(*printed)++;
	if (!fmt_lst->has_prs && fmt_lst->has_pad && !fmt_lst->has_lad)
		format_pre_conv(fmt_lst, printed, len + (di < 0));
	precision(fmt_lst, printed, ft_strlen(a));
	ft_putstr_fd(a, fmt_lst->fd);
	*printed += ft_strlen(a);
	free(a);
	format_post_conv(fmt_lst, printed, len + (di < 0));
}
