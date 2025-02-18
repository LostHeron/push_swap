/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_pushs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:58 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 14:53:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "math.h"
#include "cost_sort.h"

void	push_using_ra_rb(t_stack *a, t_stack *b, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_rr)
		inst_r_both(a, b);
	i = -1;
	while (++i < ft_abs(inst.nb_rr - inst.nb_rb))
		inst_r(b);
	i = -1;
	while (++i < ft_abs(inst.nb_rr - inst.nb_ra))
		inst_r(a);
}

void	push_using_rra_rrb(t_stack *a, t_stack *b, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_rrr)
		inst_rr_both(a, b);
	i = -1;
	while (++i < ft_abs(inst.nb_rrr - inst.nb_rrb))
		inst_rr(b);
	i = -1;
	while (++i < ft_abs(inst.nb_rrr - inst.nb_rra))
		inst_rr(a);
}

void	push_using_rra_rb(t_stack *a, t_stack *b, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_rra)
		inst_rr(a);
	i = -1;
	while (++i < inst.nb_rb)
		inst_r(b);
}

void	push_using_ra_rrb(t_stack *a, t_stack *b, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_ra)
		inst_r(a);
	i = -1;
	while (++i < inst.nb_rrb)
		inst_rr(b);
}
