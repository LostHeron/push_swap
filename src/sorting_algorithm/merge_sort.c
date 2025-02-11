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

void	merge_sort_rec(t_stack **stack_array, int *c_pos, int start, int end);
void	merge_sort_sort(t_stack **stack_array, int *c_pos, int start, int end);
void	pushing_back(t_stack **stack_array, int start, int end);
int		get_val1(t_stack b, int c_pos);
int		get_val2(t_stack b, int c_pos, int middle, int start);
void	pa_at_middle(t_stack **stack_array, int *c_pos, int middle, int start);
void	pa_at_start(t_stack **stack_array, int *c_pos);
void	my_func(t_stack **stack_array, int *pc_pos, int *p_middle, int start);
int		get_middle(int start, int end);

void	merge_sort(t_stack **stack_array)
{
	int	start;
	int	end;
	int	current_pos;

	start = 0;
	end = stack_array[0]->size;
	current_pos = 0;
	merge_sort_rec(stack_array, &current_pos, start, end);
}

void	merge_sort_rec(t_stack **stack_array, int *c_pos, int start, int end)
{
	int	middle;

	if (end - start <= 1)
		return ;
	middle = (start + end) / 2;
	merge_sort_rec(stack_array, c_pos, start, middle);
	merge_sort_rec(stack_array, c_pos, middle, end);
	merge_sort_sort(stack_array, c_pos, start, end);
}

void	merge_sort_sort(t_stack **stack_array, int *c_pos, int start, int end)
{
	int	counter;

	while (*c_pos % (stack_array[0]->size) != start)
	{
		if (start > *c_pos)
		{
			inst_r(stack_array[0]);
			(*c_pos)++;
		}
		else
		{
			inst_rr(stack_array[0]);
			(*c_pos)--;
		}
	}
	counter = 0;
	while (start + counter < end)
	{
		inst_pb(stack_array[0], stack_array[1]);
		counter++;
	}
	pushing_back(stack_array, start, end);
}

void	pushing_back(t_stack **stack_array, int start, int end)
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
		c_pos = c_pos % stack_array[1]->size;
		if (end <= middle)
		{
			pa_at_start(stack_array, &c_pos);
			middle--;
		}
		else if (middle <= start)
			pa_at_middle(stack_array, &c_pos, middle, start);
		else
			my_func(stack_array, &c_pos, &middle, start);
		end--;
		i++;
	}
	inst_pa(stack_array[0], stack_array[1]);
}

void	my_func(t_stack **stack_array, int *pc_pos, int *p_middle, int start)
{
	int	val1;
	int	val2;

	val1 = get_val1(*stack_array[1], *pc_pos);
	val2 = get_val2(*stack_array[1], *pc_pos, *p_middle, start);
	if (val1 > val2)
	{
		pa_at_start(stack_array, pc_pos);
		(*p_middle)--;
	}
	else
		pa_at_middle(stack_array, pc_pos, *p_middle, start);
}
