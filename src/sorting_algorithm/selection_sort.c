/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:04:21 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:41:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "push_swap.h"
#include "instruction.h"

static int	get_min_index(t_stack a);

int	selection_sort(t_stack **stacks)
{
	int		i;
	int		j;
	int		nb_elems;
	int		min_index;

	i = -1;
	nb_elems = stacks[STACK_A]->size;
	while (++i < nb_elems)
	{
		min_index = get_min_index(*stacks[STACK_A]);
		j = 0;
		while (j < min_index)
		{
			if (inst_ra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			j++;
		}
		if (inst_pb(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	}
	i = -1;
	while (++i < nb_elems)
		if (inst_pa(stacks, DISPLAY) < 0)
			return (WRITE_ERROR);
	return (0);
}

static int	get_min_index(t_stack a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = ((t_pair *)a.head->content)->value;
	min_index = 0;
	while (i < a.size)
	{
		if (((t_pair *)a.head->content)->value < min)
		{
			min = ((t_pair *)a.head->content)->value;
			min_index = i;
		}
		i++;
		a.head = a.head->next;
	}
	return (min_index);
}
