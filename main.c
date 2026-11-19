/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkovinia <rkovinia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:54:53 by rkovinia          #+#    #+#             */
/*   Updated: 2026/11/12 12:59:25 by rkovinia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_ps *ps, t_config *cfg)
{
	if (stack_size(ps->a) <= 5)
		sort_tiny(ps);
	else if (cfg->strategy == SIMPLE)
		sort_simple(ps);
	else if (cfg->strategy == COMPLEX)
		sort_complex(ps);
	else
		sort_medium(ps);
}

int	main(int ac, char **av)
{
	t_ps		ps;
	t_config	cfg;

	ft_bzero(&ps, sizeof(t_ps));
	cfg.strategy = ADAPTIVE;
	cfg.bench = 0;
	if (ac < 2)
		return (0);
	if (!build_stack(ac, av, &ps.a, &cfg))
		return (print_error());
	assign_index(ps.a);
	if (!is_sorted(ps.a))
		run_strategy(&ps, &cfg);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}
