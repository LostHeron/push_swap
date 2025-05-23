/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:35:37 by jweber            #+#    #+#             */
/*   Updated: 2025/02/21 11:45:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists_double_circular.h"
#include "instruction.h"
#include "merge_sort.h"
#include "push_swap.h"

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
		return (WRITE_ERROR);
	if (merge_sort_rec(stacks, c_pos, pos2, -order * -1) < 0)
		return (WRITE_ERROR);
	return (merge_sort_sort(stacks, c_pos, pos, order));
}

static int	merge_sort_sort(t_stack **stacks, int *c_pos, t_pos pos, int order)
{
	int	counter;

	if (rotate_to_start(stacks, c_pos, pos) < 0)
		return (WRITE_ERROR);
	if (pos.end - pos.start == 2)
	{
		if (case_size_two(stacks, order) < 0)
			return (WRITE_ERROR);
	}
	else
	{
		counter = -1;
		while (pos.start + ++counter < pos.end)
			if (inst_pb(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
		if (pushing_back(stacks, pos, order) < 0)
			return (WRITE_ERROR);
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
			if (inst_ra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
			(*c_pos)++;
		}
	}
	else
	{
		while (*c_pos % (stacks[0]->size) != pos.start)
		{
			if (inst_rra(stacks, DISPLAY) < 0)
				return (WRITE_ERROR);
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
			return (WRITE_ERROR);
		pos.end--;
		i++;
	}
	if (inst_pa(stacks, DISPLAY) < 0)
		return (WRITE_ERROR);
	return (0);
}
