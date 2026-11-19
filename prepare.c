/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:43:57 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/09 10:53:21 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *stack)
{
	t_node	*current;
	t_node	*other;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		other = stack;
		while (other)
		{
			if (other->value < current->value)
				count++;
			other = other->next;
		}
		current->index = count;
		current = current->next;
	}
}

double	compute_disorder(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	pairs;

	mistakes = 0;
	pairs = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0);
	return ((double)mistakes / pairs);
}
