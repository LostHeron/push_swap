/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:53:30 by jweber            #+#    #+#             */
/*   Updated: 2025/02/10 17:53:54 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "io.h"

int	get_val1(t_stack b, int c_pos, int middle, int start)
{
	while (c_pos % b.size != middle - start - 1)
	{
		b.head = b.head->next;
		c_pos++;
	}
	return (*((int *)b.head->content));
}

int	get_val2(t_stack b, int c_pos, int middle, int start)
{
	while (c_pos % b.size != middle - start)
	{
		b.head = b.head->next;
		c_pos++;
	}
	return (*((int *)b.head->content));
}

void	pa_at_start(t_stack **stack_array, int *c_pos, int middle, int start)
{
	while (*c_pos % stack_array[1]->size != middle - start - 1)
	{
		if (*c_pos % stack_array[1]->size < middle - start - 1)
		{
			inst_r(stack_array[1]);
			(*c_pos)++;
		}
		else
		{
			inst_rr(stack_array[1]);
			(*c_pos)--;
		}
	}
	inst_pa(stack_array[0], stack_array[1]);
}

void	pa_at_middle(t_stack **stack_array, int *c_pos, int middle, int start)
{
	while (*c_pos % stack_array[1]->size != middle - start)
	{
		inst_r(stack_array[1]);
		(*c_pos)++;
	}
	inst_pa(stack_array[0], stack_array[1]);
}

int	get_middle(int start, int end)
{
	int	middle;

	if ((end + start) % 2 == 1)
		middle = (start + end) / 2 + 1;
	else
		middle = (start + end) / 2;
	return (middle);
}
