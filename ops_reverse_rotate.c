/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:29:47 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/09 10:36:46 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps)
{
	reverse_rotate(&ps->a);
	record_op(ps, OP_RRA, "rra\n");
}

void	rrb(t_ps *ps)
{
	reverse_rotate(&ps->b);
	record_op(ps, OP_RRB, "rrb\n");
}

void	rrr(t_ps *ps)
{
	reverse_rotate(&ps->a);
	reverse_rotate(&ps->b);
	record_op(ps, OP_RRR, "rrr\n");
}
