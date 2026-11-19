/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:29:28 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/09 10:35:30 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	rotate(&ps->a);
	record_op(ps, OP_RA, "ra\n");
}

void	rb(t_ps *ps)
{
	rotate(&ps->b);
	record_op(ps, OP_RB, "rb\n");
}

void	rr(t_ps *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	record_op(ps, OP_RR, "rr\n");
}
