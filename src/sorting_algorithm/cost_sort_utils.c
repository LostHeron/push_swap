/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:43:48 by jweber            #+#    #+#             */
/*   Updated: 2025/02/24 12:35:45 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cost_sort.h"
#include "push_swap.h"
#include "instruction.h"
#include "math.h"
#include "sorting.h"

static int	chose_side(t_stack **stacks, int nb_rotate);

int	push_all_to_b(t_stack **stacks)
{
	int	middle;

	middle = stacks[STACK_A]->size / 2;
	if (indexing(*stacks[STACK_A]) < 0)
		return (MALLOC_FAIL);
	while (stacks[STACK_A]->size > 3)
	{
		if (((t_pair *)stacks[STACK_A]->head->content)->index > middle)
		{
			if (inst_pb(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
		}
		else
		{
			if (inst_pb(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			if (inst_rb(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
		}
	}
	return (0);
}

void	calculate_rr_and_rrr(t_inst *inst)
{
	inst->nb_rr = inst->nb_ra - inst->nb_rb;
	if (inst->nb_rr >= 0)
		inst->nb_rr = inst->nb_ra - inst->nb_rr;
	else
		inst->nb_rr = inst->nb_rb + inst->nb_rr;
	inst->nb_rrr = inst->nb_rra - inst->nb_rrb;
	if (inst->nb_rrr >= 0)
		inst->nb_rrr = inst->nb_rra - inst->nb_rrr;
	else
		inst->nb_rrr = inst->nb_rrb + inst->nb_rrr;
}

int	get_ra(t_stack a, int val_b)
{
	int		i;
	int		count_ra;
	long	diff;
	long	diff_tmp;

	i = 0;
	diff = (long)((t_pair *)a.head->content)->value - val_b;
	count_ra = i;
	while (i < a.size)
	{
		diff_tmp = (long)((t_pair *)a.head->content)->value - val_b;
		if (ft_labs(diff_tmp) < ft_labs(diff))
		{
			diff = diff_tmp;
			count_ra = i;
		}
		a.head = a.head->next;
		i++;
	}
	if (diff >= 0)
		return (count_ra);
	else
		return (count_ra + 1);
}

int	rotate_to_min(t_stack **stacks)
{
	int		i;
	int		nb_rotate;
	int		min;
	t_node	*tmp;

	tmp = stacks[STACK_A]->head;
	i = -1;
	min = ((t_pair *)stacks[STACK_A]->head->content)->value;
	nb_rotate = 0;
	while (++i < stacks[STACK_A]->size)
	{
		if (((t_pair *)tmp->content)->value < min)
		{
			min = ((t_pair *)tmp->content)->value;
			nb_rotate = i;
		}
		tmp = tmp->next;
	}
	if (chose_side(stacks, nb_rotate) < 0)
		return (WRITE_ERROR);
	return (0);
}

static int	chose_side(t_stack **stacks, int nb_rotate)
{
	int		i;

	i = -1;
	if (nb_rotate > stacks[STACK_A]->size / 2)
	{
		while (++i < stacks[STACK_A]->size - nb_rotate)
			if (inst_rra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
	}
	else
		while (++i < nb_rotate)
			if (inst_ra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
	return (0);
}
