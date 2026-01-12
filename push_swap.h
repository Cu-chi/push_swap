/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:07:13 by equentin          #+#    #+#             */
/*   Updated: 2026/01/12 10:19:11 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

typedef struct s_arguments
{
	char			simple;
	char			medium;
	char			complex;
	char			adaptive;
	char			bench;
}					t_arguments;

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_stacks;

t_stack				*ft_stacknew(int value);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
int					ft_stacksize(t_stack *lst);
t_stack				*ft_stacklast(t_stack *lst);
void				ft_stackadd_back(t_stack **lst, t_stack *new);
int					ft_atoi_ovrflw(const char *nptr, char **stack_list,
						t_stacks *stacks);
void				free_stacks(t_stacks *stacks);
void				print_stacks(t_stacks stacks);
int					exit_safe(char **stack_list, t_stacks *stacks, int fail);
void				free_stack_list(char **stack_list);
int					create_stack_node(char *str_value, char **stack_list,
						t_stacks *stacks);
int					check_duplicates(t_stacks *stacks);

void				sa(t_stacks *stacks);
void				sb(t_stacks *stacks);
void				ss(t_stacks *stacks);
void				pa(t_stacks *stacks);
void				pb(t_stacks *stacks);
void				ra(t_stacks *stacks);
void				rb(t_stacks *stacks);
void				rr(t_stacks *stacks);
void				rra(t_stacks *stacks);
void				rrb(t_stacks *stacks);
void				rrr(t_stacks *stacks);

int					is_stack_sorted(t_stacks stacks);

#endif
