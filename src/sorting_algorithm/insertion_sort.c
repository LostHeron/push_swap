/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:45:41 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:35:50 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"
#include "lists_double_circular.h"

static int	rr_and_s(t_stack **stacks);
static int	rr_while_possible(t_stack **stacks, int *i);

int	insertion_sort(t_stack **stacks)
{
	int	i;

	i = 0;
	while (i < stacks[STACK_A]->size)
	{
		if (i != 0)
		{
			if (rr_while_possible(stacks, &i) < 0)
				return (WRITE_ERROR);
		}
		else
		{
			if (inst_ra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			i++;
		}
	}
	return (0);
}

static int	rr_while_possible(t_stack **stacks, int *i)
{
	if (((t_pair *)stacks[STACK_A]->head->content)->value
		< ((t_pair *)stacks[STACK_A]->head->prev->content)->value)
	{
		if (rr_and_s(stacks) < 0)
			return (WRITE_ERROR);
		(*i)--;
	}
	else
	{
		if (inst_ra(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
		(*i)++;
	}
	return (0);
}

static int	rr_and_s(t_stack **stacks)
{
	if (inst_rra(stacks, DISPLAY) < 0)
		return (WRITE_ERROR);
	if (inst_sa(stacks, DISPLAY) < 0)
		return (WRITE_ERROR);
	return (0);
}
