/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:57:49 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/09 12:02:00 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps *ps)
{
	int	min_pos;

	while (ps->a && !is_sorted(ps->a))
	{
		min_pos = get_min_pos(ps->a);
		bring_to_top_a(ps, min_pos);
		pb(ps);
	}
	while (ps->b)
		pa(ps);
}
