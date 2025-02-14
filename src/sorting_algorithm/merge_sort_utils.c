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
	return (*((int *)b.head->content));
}

int	get_val_end(t_stack b)
{
	return (*((int *)b.head->prev->content));
}

void	case_size_two(t_stack **stacks, int order)
{
	if (order == -1)
	{
		if (*((int *)stacks[0]->head->content)
			> *((int *)stacks[0]->head->next->content))
			inst_s(stacks[0]);
	}
	else
	{
		if (*((int *)stacks[0]->head->content)
			< *((int *)stacks[0]->head->next->content))
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
