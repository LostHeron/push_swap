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

int	get_val1(t_stack b)
{
	return (*((int *)b.head->content));
}

int	get_val2(t_stack b)
{
	return (*((int *)b.head->prev->content));
}

void	pa_at_start(t_stack **stacks)
{
	inst_pa(stacks[0], stacks[1]);
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
