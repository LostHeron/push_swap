/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:44:46 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:40:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "sorting.h"
#include "cost_sort.h"
#include "ft_lists_double_circular.h"
#include "ft_math.h"
#include "push_swap.h"
#include "sorting.h"

static t_inst	get_nb_inst(t_stack a, t_stack b, int j);
static void		calculate_nb_inst(t_inst *ptr_inst);
static int		chose_push(t_stack **stacks);
static int		push_using(t_stack **stacks, t_inst inst);

int	cost_sort(t_stack **stacks)
{
	int	ret;

	ret = push_all_to_b(stacks);
	if (ret < 0)
		return (ret);
	if (sort_three(stacks) < 0)
		return (WRITE_ERROR);
	while (stacks[STACK_B]->size > 0)
	{
		if (chose_push(stacks) < 0)
			return (WRITE_ERROR);
	}
	if (rotate_to_min(stacks) < 0)
		return (WRITE_ERROR);
	return (0);
}

static int	chose_push(t_stack **stacks)
{
	int		j;
	t_inst	inst_tmp;
	t_inst	inst;

	j = 0;
	inst = get_nb_inst(*stacks[STACK_A], *stacks[STACK_B], j);
	while (j < stacks[STACK_B]->size)
	{
		inst_tmp = get_nb_inst(*stacks[STACK_A], *stacks[STACK_B], j);
		if (inst_tmp.nb_inst < inst.nb_inst)
		{
			inst = inst_tmp;
		}
		j++;
	}
	if (push_using(stacks, inst) < 0)
		return (WRITE_ERROR);
	return (0);
}

static t_inst	get_nb_inst(t_stack a, t_stack b, int j)
{
	int		i;
	int		val_b;
	t_inst	inst;

	i = 0;
	while (i < j)
	{
		b.head = b.head->next;
		i++;
	}
	inst.nb_rb = j % b.size;
	val_b = ((t_pair *)b.head->content)->value;
	inst.nb_ra = get_ra(a, val_b) % a.size;
	inst.nb_rra = (a.size - inst.nb_ra) % a.size;
	inst.nb_rrb = (b.size - inst.nb_rb) % b.size;
	calculate_rr_and_rrr(&inst);
	calculate_nb_inst(&inst);
	return (inst);
}

static void	calculate_nb_inst(t_inst *ptr_inst)
{
	int	nb_inst_tmp;

	nb_inst_tmp = ptr_inst->nb_rr + ft_abs(ptr_inst->nb_rr - ptr_inst->nb_ra)
		+ ft_abs(ptr_inst->nb_rr - ptr_inst->nb_rb);
	ptr_inst->nb_inst = nb_inst_tmp;
	ptr_inst->type = 1;
	nb_inst_tmp = ptr_inst->nb_rrr + ft_abs(ptr_inst->nb_rrr - ptr_inst->nb_rra)
		+ ft_abs(ptr_inst->nb_rrr - ptr_inst->nb_rrb);
	if (nb_inst_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = nb_inst_tmp;
		ptr_inst->type = 2;
	}
	nb_inst_tmp = ptr_inst->nb_rb + ptr_inst->nb_rra;
	if (nb_inst_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = nb_inst_tmp;
		ptr_inst->type = 3;
	}
	nb_inst_tmp = ptr_inst->nb_rrb + ptr_inst->nb_ra;
	if (nb_inst_tmp < ptr_inst->nb_inst)
	{
		ptr_inst->nb_inst = nb_inst_tmp;
		ptr_inst->type = 4;
	}
}

static int	push_using(t_stack **stacks, t_inst inst)
{
	if (inst.type == 1)
	{
		if (push_using_ra_rb(stacks, inst) < 0)
			return (WRITE_ERROR);
	}
	else if (inst.type == 2)
	{
		if (push_using_rra_rrb(stacks, inst) < 0)
			return (WRITE_ERROR);
	}
	else if (inst.type == 3)
	{
		if (push_using_rra_rb(stacks, inst) < 0)
			return (WRITE_ERROR);
	}
	else if (inst.type == 4)
	{
		if (push_using_ra_rrb(stacks, inst) < 0)
			return (WRITE_ERROR);
	}
	if (inst_pa(stacks, DISPLAY) < 0)
		return (WRITE_ERROR);
	return (0);
}
