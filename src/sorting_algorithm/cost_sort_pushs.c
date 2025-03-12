/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_pushs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:46:58 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:39:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "instruction.h"
#include "ft_math.h"
#include "cost_sort.h"
#include "push_swap.h"

int	push_using_ra_rb(t_stack **stacks, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_rr)
		if (inst_rr(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	i = -1;
	while (++i < ft_abs(inst.nb_rr - inst.nb_rb))
		if (inst_rb(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	i = -1;
	while (++i < ft_abs(inst.nb_rr - inst.nb_ra))
		if (inst_ra(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}

int	push_using_rra_rrb(t_stack **stacks, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_rrr)
		if (inst_rrr(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	i = -1;
	while (++i < ft_abs(inst.nb_rrr - inst.nb_rrb))
		if (inst_rrb(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	i = -1;
	while (++i < ft_abs(inst.nb_rrr - inst.nb_rra))
		if (inst_rra(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}

int	push_using_rra_rb(t_stack **stacks, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_rra)
		if (inst_rra(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	i = -1;
	while (++i < inst.nb_rb)
		if (inst_rb(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}

int	push_using_ra_rrb(t_stack **stacks, t_inst inst)
{
	int	i;

	i = -1;
	while (++i < inst.nb_ra)
		if (inst_ra(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	i = -1;
	while (++i < inst.nb_rrb)
		if (inst_rrb(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}
