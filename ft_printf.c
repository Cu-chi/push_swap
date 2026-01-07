/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:57:17 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:33 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_printf_logic(t_format_list *fmt_lst, int *printed, va_list *ap)
{
	(void)ap;
	if (fmt_lst->c == '%')
	{
		(*printed)++;
		ft_putchar_fd(fmt_lst->c, 1);
	}
	else if (fmt_lst->c == 'c')
		write_c(fmt_lst, printed, ap);
	else if (fmt_lst->c == 's')
		write_s(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'd' || fmt_lst->c == 'i')
		write_di(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'u')
		write_u(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'x' || fmt_lst->c == 'X')
		write_x(fmt_lst, printed, ap);
	else if (fmt_lst->c == 'p')
		write_p(fmt_lst, printed, ap);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			ap;
	int				printed;
	t_format_list	*fmt_lst;

	va_start(ap, fmt);
	printed = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt_lst = ft_get_format(fmt + 1);
			if (fmt_lst == NULL)
				return (0);
			ft_printf_logic(fmt_lst, &printed, &ap);
			fmt += fmt_lst->new_index + 2;
			free(fmt_lst);
		}
		else
		{
			write(1, fmt++, 1);
			printed++;
		}
	}
	va_end(ap);
	return (printed);
}
