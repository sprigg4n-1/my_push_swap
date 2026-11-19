/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:32:21 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/12 12:39:47 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flag(char *arg, t_config *cfg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		cfg->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		cfg->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		cfg->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		cfg->strategy = ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		cfg->bench = 1;
	else
		return (0);
	return (1);
}

static int	add_number(char *str, t_node **a_stack)
{
	int		n;
	t_node	*node;

	if (!is_valid_number(str) || !ft_atoi_safe(str, &n)
		|| has_duplicate(*a_stack, n))
		return (0);
	node = create_new_node(n);
	if (!node)
		return (0);
	stack_add_back(a_stack, node);
	return (1);
}

int	build_stack(int ac, char **av, t_node **a_stack, t_config *cfg)
{
	int	i;
	int	seen_num;
	int	tail;

	i = 1;
	seen_num = 0;
	tail = 0;
	while (i < ac)
	{
		if (parse_flag(av[i], cfg))
			tail = seen_num;
		else if (tail || !add_number(av[i], a_stack))
		{
			free_stack(a_stack);
			return (0);
		}
		else
			seen_num = 1;
		i++;
	}
	return (1);
}
