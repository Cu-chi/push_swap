/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:07:13 by equentin          #+#    #+#             */
/*   Updated: 2026/01/15 11:09:51 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/includes/ft_printf.h"
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
	int				nb_values;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_stacks;

void				init_stacks(t_stacks *stacks);
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
int					ft_sqrt(int n);
void				run_benchmark(void algorithm(t_stacks *));
int					args_checker(int ac, char **av, t_arguments *args,
						t_stacks *stacks);

void				sa(t_stacks *stacks, char ss);
void				sb(t_stacks *stacks, char ss);
void				ss(t_stacks *stacks);
void				pa(t_stacks *stacks);
void				pb(t_stacks *stacks);
void				ra(t_stacks *stacks, char rr);
void				rb(t_stacks *stacks, char rr);
void				rr(t_stacks *stacks);
void				rra(t_stacks *stacks, char rrr);
void				rrb(t_stacks *stacks, char rrr);
void				rrr(t_stacks *stacks);

int					is_stack_sorted(t_stacks stacks);
// simple sort
int					get_min_index(t_stack *stack);
void				selection_sort(t_stacks *stacks);
// medium sort
int					*preprocess_values(t_stacks *stacks);
void				chunk_based_sort(t_stacks *stacks);
// complex sort
void				lsb_radix_sort(t_stacks *stacks);

#endif
