/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:35:37 by jweber            #+#    #+#             */
/*   Updated: 2025/02/19 10:59:24 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "merge_sort.h"

static int	merge_sort_rec(t_stack **stacks, int *c_pos, t_pos pos, int order);
static int	merge_sort_sort(t_stack **stacks, int *c_pos, t_pos pos, int order);
static int	pushing_back(t_stack **stacks, t_pos pos, int order);
static int	rotate_to_start(t_stack **stacks, int *c_pos, t_pos pos);

int	merge_sort(t_stack **stack_array)
{
	int		current_pos;
	t_pos	init_pos;

	init_pos.start = 0;
	init_pos.end = stack_array[0]->size;
	current_pos = 0;
	return (merge_sort_rec(stack_array, &current_pos, init_pos, -1));
}

static int	merge_sort_rec(t_stack **stacks, int *c_pos, t_pos pos, int order)
{
	int		middle;
	t_pos	pos1;
	t_pos	pos2;

	if (pos.end - pos.start <= 1)
		return (0);
	middle = (pos.start + pos.end) / 2;
	pos1.start = pos.start;
	pos1.end = middle;
	pos2.start = middle;
	pos2.end = pos.end;
	if (merge_sort_rec(stacks, c_pos, pos1, order * -1) < 0)
		return (-1);
	if (merge_sort_rec(stacks, c_pos, pos2, -order * -1) < 0)
		return (-1);
	return (merge_sort_sort(stacks, c_pos, pos, order));
}

static int	merge_sort_sort(t_stack **stacks, int *c_pos, t_pos pos, int order)
{
	int	counter;

	if (rotate_to_start(stacks, c_pos, pos) < 0)
		return (-1);
	if (pos.end - pos.start == 2)
	{
		if (case_size_two(stacks, order) < 0)
			return (-1);
	}
	else
	{
		counter = -1;
		while (pos.start + ++counter < pos.end)
			if (inst_pb(stacks[0], stacks[1]) < 0)
				return (-1);
		if (pushing_back(stacks, pos, order) < 0)
			return (-1);
	}
	*c_pos = pos.start;
	return (0);
}

static int	rotate_to_start(t_stack **stacks, int *c_pos, t_pos pos)
{
	if (pos.start > *c_pos)
	{
		while (*c_pos % (stacks[0]->size) != pos.start)
		{
			if (inst_r(stacks[0]) < 0)
				return (-1);
			(*c_pos)++;
		}
	}
	else
	{
		while (*c_pos % (stacks[0]->size) != pos.start)
		{
			if (inst_rr(stacks[0]) < 0)
				return (-1);
			(*c_pos)--;
		}
	}
	return (0);
}

static int	pushing_back(t_stack **stacks, t_pos pos, int order)
{
	int		i;
	int		c_pos;
	int		middle;
	int		nb_elems;

	nb_elems = pos.end - pos.start;
	middle = get_middle(pos.start, pos.end);
	i = 0;
	c_pos = 0;
	while (i < nb_elems - 1)
	{
		c_pos = c_pos % stacks[1]->size;
		if (push_case(stacks, &middle, pos, order) < 0)
			return (-1);
		pos.end--;
		i++;
	}
	if (inst_pa(stacks[0], stacks[1]) < 0)
		return (-1);
	return (0);
}
