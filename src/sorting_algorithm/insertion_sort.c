/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:45:41 by jweber            #+#    #+#             */
/*   Updated: 2025/02/18 18:07:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "push_swap.h"
#include "lists_double_circular.h"

static int	rr_and_s(t_stack *a);
static int	rr_while_possible(t_stack *a, int *i);

int	insertion_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (i != 0)
		{
			if (rr_while_possible(a, &i) < 0)
				return (-1);
		}
		else
		{
			if (inst_r(a, DISPLAY) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}

static int	rr_while_possible(t_stack *a, int *i)
{
	if (((t_pair *)a->head->content)->value
		< ((t_pair *)a->head->prev->content)->value)
	{
		if (rr_and_s(a) < 0)
			return (-1);
		(*i)--;
	}
	else
	{
		if (inst_r(a, DISPLAY) < 0)
			return (-1);
		(*i)++;
	}
	return (0);
}

static int	rr_and_s(t_stack *a)
{
	if (inst_rr(a, DISPLAY) < 0)
		return (-1);
	if (inst_s(a, DISPLAY) < 0)
		return (-1);
	return (0);
}
