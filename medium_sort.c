/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:08:01 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/16 12:39:41 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int n)
{
	int	r;

	r = 1;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static void	push_chunks(t_ps *ps, int chunk)
{
	int	i;

	i = 0;
	while (ps->a)
	{
		if (ps->a->index <= i)
		{
			pb(ps);
			rb(ps);
			i++;
		}
		else if (ps->a->index <= i + chunk)
		{
			pb(ps);
			i++;
		}
		else
			ra(ps);
	}
}

void	sort_medium(t_ps *ps)
{
	int	chunk;

	chunk = ft_sqrt(stack_size(ps->a));
	push_chunks(ps, chunk);
	while (ps->b)
	{
		bring_to_top_b(ps, get_max_pos(ps->b));
		pa(ps);
	}
}
