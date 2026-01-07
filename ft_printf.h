/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:44:08 by equentin          #+#    #+#             */
/*   Updated: 2025/11/18 15:21:49 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*
%[format][width][precision]conv
*/
typedef struct s_format_list
{
	/*
	'#'
	adds 0x (0X for X) before val for x X conversion (for xX > 0)
	*/
	char		has_hex;
	/*
	'0'
	pad with '0' instead of ' '
	ignored if '-' or precision secified for nb
	d i u x X only
	*/
	char		has_pad;
	/*
	'-'
	space on right instead of left
	overrides '0'
	all conv
	*/
	char		has_lad; // '-'
	/*
	' '
	adds ' ' before positive numbers
	ignored if '+'
	d i only
	*/
	char		has_blk; // ' '
	/*
	'+'
	adds '+' sign before positive numbers
	overrides ' '
	d i only
	*/
	char		has_sgn; // '+'
	/*
	'.'
	d i u x X : nb of digits (pads with 0)
	s : max nb of chars to print
	overrides '0'
	*/
	char		has_prs; // '.'
	/*
	min field width (pads with space or '0' if flag has_pad)
	all conv
	*/
	int			width;
	int			precision; // number of precision
	char		c; // conversion char
	size_t		new_index; // new index of i in the loop after parse
}				t_format_list;

t_format_list	*ft_get_format(const char *s);
int				ft_printf(const char *fmt, ...);
void			write_c(t_format_list *fmt_lst, int *printed, va_list *ap);
void			write_s(t_format_list *fmt_lst, int *printed, va_list *ap);
void			write_x(t_format_list *fmt_lst, int *printed, va_list *ap);
void			write_p(t_format_list *fmt_lst, int *printed, va_list *ap);
void			write_c(t_format_list *fmt_lst, int *printed, va_list *ap);
void			write_di(t_format_list *fmt_lst, int *printed, va_list *ap);
void			write_u(t_format_list *fmt_lst, int *printed, va_list *ap);
int				format_pre_conv(t_format_list *fmt_lst, int *printed,
					int conv_len);
int				format_post_conv(t_format_list *fmt_lst, int *printed,
					int conv_len);
int				precision(t_format_list *fmt_lst, int *printed,
					int conv_len);
char			*ft_itoa_u(unsigned int n);
void			ft_putnbr_hex(unsigned long nbr, char *base, int *printed);
int				count_digits_base(size_t nb, int base);
void			only_format(t_format_list *fmt_lst, int *printed);
#endif
