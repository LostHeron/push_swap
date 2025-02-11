/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:53:30 by jweber            #+#    #+#             */
/*   Updated: 2025/02/11 16:52:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "push_swap.h"

int	get_val1(t_stack b, int c_pos)
{
	while (c_pos % b.size != 0)
	{
		b.head = b.head->prev;
		c_pos--;
	}
	return (((t_pair *)b.head->content)->value);
}

int	get_val2(t_stack b, int c_pos, int middle, int start)
{
	while (c_pos % b.size != middle - start)
	{
		b.head = b.head->next;
		c_pos++;
	}
	return (((t_pair *)b.head->content)->value);
}

void	pa_at_start(t_stack **stack_array, int *c_pos)
{
	while (*c_pos % stack_array[1]->size != 0)
	{
		inst_rr(stack_array[1]);
		(*c_pos)--;
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
