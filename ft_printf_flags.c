/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:23:49 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:48 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	format_pre_conv(t_format_list *fmt_lst, int *printed, int conv_len)
{
	char	*str;

	if (fmt_lst->width > conv_len && !fmt_lst->has_lad)
	{
		str = malloc(sizeof(char) * (fmt_lst->width - conv_len + 1));
		if (str == NULL)
			return (0);
		str[fmt_lst->width - conv_len] = 0;
		if (fmt_lst->has_pad && !fmt_lst->has_prs)
			ft_memset(str, '0', fmt_lst->width - conv_len);
		else
			ft_memset(str, ' ', fmt_lst->width - conv_len);
		ft_putstr_fd(str, 1);
		*printed += fmt_lst->width - conv_len;
		free(str);
	}
	return (1);
}

int	format_post_conv(t_format_list *fmt_lst, int *printed, int conv_len)
{
	char	*str;

	if (fmt_lst->width > conv_len && fmt_lst->has_lad)
	{
		str = malloc(sizeof(char) * (fmt_lst->width - conv_len + 1));
		if (str == NULL)
			return (0);
		str[fmt_lst->width - conv_len] = 0;
		ft_memset(str, ' ', fmt_lst->width - conv_len);
		ft_putstr_fd(str, 1);
		*printed += fmt_lst->width - conv_len;
		free(str);
	}
	return (1);
}

int	precision(t_format_list *fmt_lst, int *printed, int conv_len)
{
	char	*str;

	if (fmt_lst->precision > conv_len)
	{
		str = malloc(sizeof(char) * (fmt_lst->precision - conv_len + 1));
		if (str == NULL)
			return (0);
		str[fmt_lst->precision - conv_len] = 0;
		ft_memset(str, '0', fmt_lst->precision - conv_len);
		ft_putstr_fd(str, 1);
		*printed += fmt_lst->precision - conv_len;
		free(str);
	}
	return (1);
}
