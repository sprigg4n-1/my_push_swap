/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:43:22 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/12 12:58:47 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_config
{
	int	strategy;
	int	bench;
}	t_config;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		ops[11];
}	t_ps;

t_node	*create_new_node(int value);
t_node	*stack_last_node(t_node *stack);
void	stack_add_back(t_node **stack, t_node *new);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);

int		print_error(void);

int		is_valid_number(char *number);
int		ft_atoi_safe(char *str, int *out);
int		has_duplicate(t_node *stack, int value);

int		build_stack(int ac, char **av, t_node **a_stack, t_config *cfg);

void	swap(t_node **stack);
void	push(t_node **src, t_node **dst);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);

void	record_op(t_ps *ps, int op, char *name);

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);

void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);

void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

void	assign_index(t_node *stack);
double	compute_disorder(t_node *stack);

int		is_sorted(t_node *stack);
int		get_min_pos(t_node *stack);
int		get_max_pos(t_node *stack);
void	bring_to_top_a(t_ps *ps, int pos);
void	bring_to_top_b(t_ps *ps, int pos);

void	sort_simple(t_ps *ps);
void	sort_medium(t_ps *ps);

void	quick_a(t_ps *ps, int lo, int n);
void	quick_b(t_ps *ps, int lo, int n);
void	sort_complex(t_ps *ps);

void	sort_two(t_ps *ps);
void	sort_three(t_ps *ps);
void	sort_to_five(t_ps *ps);
void	sort_tiny(t_ps *ps);

#endif
