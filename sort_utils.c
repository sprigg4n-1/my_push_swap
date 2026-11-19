/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 11:38:06 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/11 17:07:44 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_min_pos(t_node *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	pos = 0;
	min_pos = 0;
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

int	get_max_pos(t_node *stack)
{
	int	max;
	int	pos;
	int	max_pos;

	pos = 0;
	max_pos = 0;
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

void	bring_to_top_a(t_ps *ps, int pos)
{
	int	size;

	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(ps);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(ps);
			pos--;
		}
	}
}

void	bring_to_top_b(t_ps *ps, int pos)
{
	int	size;

	size = stack_size(ps->b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(ps);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(ps);
			pos--;
		}
	}
}
