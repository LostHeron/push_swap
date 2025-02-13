/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:35:37 by jweber            #+#    #+#             */
/*   Updated: 2025/02/10 18:40:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "io.h"

static void	merge_sort_rec(t_stack **stacks, int *c_pos, int start, int end);
static void	merge_sort_sort(t_stack **stacks, int *c_pos, int start, int end);
static void	pushing_back(t_stack **stacks, int start, int end, int *c_pos_a);
static void	chose_push(t_stack **stacks, int *pc_pos, int *p_middle, int start);
int			get_val1(t_stack b, int c_pos, int middle, int start);
int			get_val2(t_stack b, int c_pos, int middle, int start);
void		pa_at_start(t_stack **stack_array,
				int *c_pos, int middle, int start);
void		pa_at_middle(t_stack **stacks, int *c_pos, int middle, int start);
int			get_middle(int start, int end);

void	merge_sort(t_stack **stack_array)
{
	int	start;
	int	end;
	int	current_pos;

	ft_printf_fd(1, "dans merge_sort la vrai \n");
	start = 0;
	end = stack_array[0]->size;
	current_pos = 0;
	merge_sort_rec(stack_array, &current_pos, start, end);
}

static void	merge_sort_rec(t_stack **stacks, int *c_pos, int start, int end)
{
	int	middle;

	if (end - start <= 1)
		return ;
	middle = (start + end) / 2;
	merge_sort_rec(stacks, c_pos, start, middle);
	merge_sort_rec(stacks, c_pos, middle, end);
	merge_sort_sort(stacks, c_pos, start, end);
}

static void	merge_sort_sort(t_stack **stacks, int *c_pos, int start, int end)
{
	int	counter;
	int	middle;
	int	nb_elems;

	middle = (start + end) / 2 ;
	nb_elems = stacks[0]->size;
	while (*c_pos % (stacks[0]->size) != start)
	{
		if (start > *c_pos)
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
	if (end - start == 2)
	{
		if (*((int *)stacks[0]->head->content)
			> *((int *)stacks[0]->head->next->content))
			inst_s(stacks[0]);
	}
	else
	{
		counter = 0;
		while (start + counter < middle)
		{
			inst_pb(stacks[0], stacks[1]);
			counter++;
		}
		while (*c_pos % (nb_elems) != end - counter)
		{
			if (end - 1 > *c_pos)
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
		counter = 0;
		while (end - counter > middle)
		{
			inst_rr(stacks[0]);
			inst_pb(stacks[0], stacks[1]);
			counter++;
		}
		pushing_back(stacks, start, end, c_pos);
	}
	*c_pos = start;
}

static void	pushing_back(t_stack **stacks, int start, int end, int *c_pos_a)
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
		if (end <= middle)
		{
			pa_at_start(stacks, &c_pos, middle, start);
			middle--;
		}
		else if (middle <= start)
			pa_at_middle(stacks, &c_pos, middle, start);
		else
			chose_push(stacks, &c_pos, &middle, start);
		(*c_pos_a)--;
		end--;
		i++;
	}
	inst_pa(stacks[0], stacks[1]);
	//(*c_pos_a)--;
}

static void	chose_push(t_stack **stacks, int *pc_pos, int *p_middle, int start)
{
	int	val1;
	int	val2;

	val1 = get_val1(*stacks[1], *pc_pos, *p_middle, start);
	val2 = get_val2(*stacks[1], *pc_pos, *p_middle, start);
	if (val1 > val2)
	{
		pa_at_start(stacks, pc_pos, *p_middle, start);
		(*p_middle)--;
	}
	else
		pa_at_middle(stacks, pc_pos, *p_middle, start);
}
