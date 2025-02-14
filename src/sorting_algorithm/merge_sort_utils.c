/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:53:30 by jweber            #+#    #+#             */
/*   Updated: 2025/02/14 12:18:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists_double_circular.h"
#include "instruction.h"
#include "push_swap.h"

int	get_val_start(t_stack b)
{
	return (((t_pair *)b.head->content)->value);
}

int	get_val_end(t_stack b)
{
	return (((t_pair *)b.head->prev->content)->value);
}

void	case_size_two(t_stack **stacks, int order)
{
	if (order == -1)
	{
		if (((t_pair *)stacks[0]->head->content)->value
			> ((t_pair *)stacks[0]->head->next->content)->value)
			inst_s(stacks[0]);
	}
	else
	{
		if (((t_pair *)stacks[0]->head->content)->value
			< ((t_pair *)stacks[0]->head->next->content)->value)
			inst_s(stacks[0]);
	}
}

void	pa_at_end(t_stack **stacks)
{
	inst_rr(stacks[1]);
	inst_pa(stacks[0], stacks[1]);
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
