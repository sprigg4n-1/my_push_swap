/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:37:36 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/12 12:35:22 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_a(t_ps *ps, int pivot, int small, int large)
{
	int	pushed;
	int	rot;

	pushed = 0;
	rot = 0;
	while (pushed < small)
	{
		if (ps->a->index < pivot)
		{
			pb(ps);
			pushed++;
		}
		else
		{
			ra(ps);
			rot++;
		}
	}
	if (stack_size(ps->a) == large)
		return ;
	while (rot > 0)
	{
		rra(ps);
		rot--;
	}
}

static void	partition_b(t_ps *ps, int pivot, int small, int large)
{
	int	pushed;
	int	rot;

	pushed = 0;
	rot = 0;
	while (pushed < large)
	{
		if (ps->b->index >= pivot)
		{
			pa(ps);
			pushed++;
		}
		else
		{
			rb(ps);
			rot++;
		}
	}
	if (stack_size(ps->b) == small)
		return ;
	while (rot > 0)
	{
		rrb(ps);
		rot--;
	}
}

void	quick_a(t_ps *ps, int lo, int n)
{
	int	small;
	int	pivot;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if (ps->a->index > ps->a->next->index)
			sa(ps);
		return ;
	}
	small = n / 2;
	pivot = lo + small;
	partition_a(ps, pivot, small, n - small);
	quick_a(ps, pivot, n - small);
	quick_b(ps, lo, small);
}

void	quick_b(t_ps *ps, int lo, int n)
{
	int	small;
	int	pivot;

	if (n == 0)
		return ;
	if (n == 1)
	{
		pa(ps);
		return ;
	}
	if (n == 2)
	{
		if (ps->b->index < ps->b->next->index)
			sb(ps);
		pa(ps);
		pa(ps);
		return ;
	}
	small = n / 2;
	pivot = lo + small;
	partition_b(ps, pivot, small, n - small);
	quick_a(ps, pivot, n - small);
	quick_b(ps, lo, small);
}

void	sort_complex(t_ps *ps)
{
	quick_a(ps, 0, stack_size(ps->a));
}
