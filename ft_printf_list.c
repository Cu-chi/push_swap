/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:46:57 by equentin          #+#    #+#             */
/*   Updated: 2026/01/07 12:58:42 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	is_flag(t_format_list *fmt, char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
	{
		if (c == '#')
			fmt->has_hex = 1;
		else if (c == '0')
			fmt->has_pad = 1;
		else if (c == '-')
			fmt->has_lad = 1;
		else if (c == ' ')
			fmt->has_blk = 1;
		else if (c == '+')
			fmt->has_sgn = 1;
		return (1);
	}
	return (0);
}

// %c %s %p %d %i %u %x %X %%
static int	is_valid_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

/*
%[format][width][precision]conv
*/
t_format_list	*ft_get_format(const char *s)
{
	t_format_list	*fmt;
	size_t			i;

	fmt = (t_format_list *)ft_calloc(1, sizeof(t_format_list));
	if (fmt == NULL)
		return (NULL);
	i = 0;
	while (is_flag(fmt, s[i]))
		i++;
	while (ft_isdigit(s[i]))
		fmt->width = fmt->width * 10 + s[i++] - '0';
	if (s[i] == '.')
		fmt->has_prs = 1;
	if (s[i] == '.')
		while (ft_isdigit(s[++i]))
			fmt->precision = fmt->precision * 10 + s[i] - '0';
	if (is_valid_conversion(s[i]))
		fmt->c = s[i];
	else
	{
		free(fmt);
		return (NULL);
	}
	fmt->new_index = i;
	return (fmt);
}
