/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:35:37 by jweber            #+#    #+#             */
/*   Updated: 2025/02/14 12:18:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "merge_sort.h"

static void	merge_sort_rec(t_stack **stacks, int *c_pos, t_pos pos, int order);
static void	merge_sort_sort(t_stack **stacks, int *c_pos, t_pos pos, int order);
static void	pushing_back(t_stack **stacks, int start, int end, int order);
static void	chose_push(t_stack **stacks, int *p_middle, int order);
void		case_size_two(t_stack **stacks, int order);
int			get_val_start(t_stack b);
int			get_val_end(t_stack b);
void		pa_at_end(t_stack **stacks);
int			get_middle(int start, int end);

void	merge_sort(t_stack **stack_array)
{
	int		current_pos;
	t_pos	init_pos;

	init_pos.start = 0;
	init_pos.end = stack_array[0]->size;
	current_pos = 0;
	merge_sort_rec(stack_array, &current_pos, init_pos, -1);
}

static void	merge_sort_rec(t_stack **stacks, int *c_pos, t_pos pos, int order)
{
	int		middle;
	t_pos	pos1;
	t_pos	pos2;

	if (pos.end - pos.start <= 1)
		return ;
	middle = (pos.start + pos.end) / 2;
	pos1.start = pos.start;
	pos1.end = middle;
	pos2.start = middle;
	pos2.end = pos.end;
	merge_sort_rec(stacks, c_pos, pos1, order * -1);
	merge_sort_rec(stacks, c_pos, pos2, -order * -1);
	merge_sort_sort(stacks, c_pos, pos, order);
}

static void	merge_sort_sort(t_stack **stacks, int *c_pos, t_pos pos, int order)
{
	int	counter;

	while (*c_pos % (stacks[0]->size) != pos.start)
	{
		if (pos.start > *c_pos)
		{
			inst_r(stacks[0]);
			(*c_pos)++;
		}
		else
		{
			inst_rr(stacks[0]);
			(*c_pos)--;
		}
	}
	if (pos.end - pos.start == 2)
		case_size_two(stacks, order);
	else
	{
		counter = -1;
		while (pos.start + ++counter < pos.end)
			inst_pb(stacks[0], stacks[1]);
		pushing_back(stacks, pos.start, pos.end, order);
	}
	*c_pos = pos.start;
}

static void	pushing_back(t_stack **stacks, int start, int end, int order)
{
	int		i;
	int		c_pos;
	int		middle;
	int		nb_elems;

	nb_elems = end - start;
	middle = get_middle(start, end);
	i = 0;
	c_pos = 0;
	while (i < nb_elems - 1)
	{
		c_pos = c_pos % stacks[1]->size;
		if (end < middle)
		{
			inst_pa(stacks[0], stacks[1]);
			middle--;
		}
		else if (middle <= start)
			pa_at_end(stacks);
		else
			chose_push(stacks, &middle, order);
		end--;
		i++;
	}
	inst_pa(stacks[0], stacks[1]);
}

static void	chose_push(t_stack **stacks, int *p_middle, int order)
{
	int	val_start;
	int	val_end;

	val_start = get_val_start(*stacks[1]);
	val_end = get_val_end(*stacks[1]);
	if (order == -1)
	{
		if (val_start > val_end)
		{
			inst_pa(stacks[0], stacks[1]);
			(*p_middle)--;
		}
		else
			pa_at_end(stacks);
	}
	else
	{
		if (val_start > val_end)
			pa_at_end(stacks);
		else
		{
			inst_pa(stacks[0], stacks[1]);
			(*p_middle)--;
		}
	}
}
