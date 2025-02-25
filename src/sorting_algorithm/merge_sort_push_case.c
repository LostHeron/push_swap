/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_push_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:55:59 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:47:59 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"
#include "instruction.h"
#include "lists_double_circular.h"
#include "push_swap.h"

static int	chose_push(t_stack **stacks, int *p_middle, int order);
static int	pa_ord_neg(t_stack **stacks, int *p_mid, int val_start, int valend);
static int	pa_ord_pos(t_stack **stacks, int *p_mid, int val_start, int valend);

int	push_case(t_stack **stacks, int *middle, t_pos pos, int order)
{
	if (pos.end < *middle)
	{
		if (inst_pa(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
		(*middle)--;
	}
	else if (*middle <= pos.start)
	{
		if (pa_at_end(stacks) < 0)
			return (WRITE_ERROR);
	}
	else
		if (chose_push(stacks, middle, order) < 0)
			return (WRITE_ERROR);
	return (0);
}

static int	chose_push(t_stack **stacks, int *p_middle, int order)
{
	int	val_start;
	int	val_end;

	val_start = get_val_start(*stacks[1]);
	val_end = get_val_end(*stacks[1]);
	if (order == -1)
	{
		pa_ord_neg(stacks, p_middle, val_start, val_end);
	}
	else
	{
		pa_ord_pos(stacks, p_middle, val_start, val_end);
	}
	return (0);
}

static int	pa_ord_neg(t_stack **stacks, int *p_mid, int val_start, int val_end)
{
	if (val_start > val_end)
	{
		if (inst_pa(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
		(*p_mid)--;
	}
	else
		if (pa_at_end(stacks) < 0)
			return (WRITE_ERROR);
	return (0);
}

static int	pa_ord_pos(t_stack **stacks, int *p_mid, int val_start, int val_end)
{
	if (val_start > val_end)
	{
		if (pa_at_end(stacks) < 0)
			return (WRITE_ERROR);
	}
	else
	{
		if (inst_pa(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
		(*p_mid)--;
	}
	return (0);
}
