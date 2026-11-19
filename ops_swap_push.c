/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:23:00 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/09 10:27:27 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	swap(&ps->a);
	record_op(ps, OP_SA, "sa\n");
}

void	sb(t_ps *ps)
{
	swap(&ps->b);
	record_op(ps, OP_SB, "sb\n");
}

void	ss(t_ps *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	record_op(ps, OP_SS, "ss\n");
}

void	pa(t_ps *ps)
{
	push(&ps->b, &ps->a);
	record_op(ps, OP_PA, "pa\n");
}

void	pb(t_ps *ps)
{
	push(&ps->a, &ps->b);
	record_op(ps, OP_PB, "pb\n");
}
