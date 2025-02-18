/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:43:48 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 17:12:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cost_sort.h"
#include "push_swap.h"
#include "instruction.h"
#include "math.h"
#include "sorting.h"

void	push_all_to_b(t_stack *a, t_stack *b)
{
	int	middle;

	middle = a->size / 2;
	indexing(*a);
	while (a->size > 3)
	{
		if (((t_pair *)a->head->content)->index > middle)
			inst_pb(a, b);
		else
		{
			inst_pb(a, b);
			inst_r(b);
		}
	}
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

void	rotate_to_min(t_stack *a)
{
	int		i;
	int		nb_rotate;
	int		min;
	t_node	*tmp;

	tmp = a->head;
	i = -1;
	min = ((t_pair *)a->head->content)->value;
	nb_rotate = 0;
	while (++i < a->size)
	{
		if (((t_pair *)tmp->content)->value < min)
		{
			min = ((t_pair *)tmp->content)->value;
			nb_rotate = i;
		}
		tmp = tmp->next;
	}
	i = -1;
	if (nb_rotate > a->size / 2)
		while (++i < a->size - nb_rotate)
			inst_rr(a);
	else
		while (++i < nb_rotate)
			inst_r(a);
}
