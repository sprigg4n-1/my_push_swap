/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:44:47 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/12 12:59:15 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_ps *ps)
{
	if (ps->a->index > ps->a->next->index)
		sa(ps);
}

void	sort_three(t_ps *ps)
{
	int	max_pos;

	max_pos = get_max_pos(ps->a);
	if (max_pos == 0)
		ra(ps);
	else if (max_pos == 1)
		rra(ps);
	if (ps->a->index > ps->a->next->index)
		sa(ps);
}

void	sort_to_five(t_ps *ps)
{
	while (stack_size(ps->a) > 3)
	{
		bring_to_top_a(ps, get_min_pos(ps->a));
		pb(ps);
	}
	sort_three(ps);
	while (ps->b)
		pa(ps);
}

void	sort_tiny(t_ps *ps)
{
	int	size;

	size = stack_size(ps->a);
	if (size == 2)
		sort_two(ps);
	else if (size == 3)
		sort_three(ps);
	else
		sort_to_five(ps);
}
