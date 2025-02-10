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

int	get_val1(t_stack b, int c_pos)
{
	while (c_pos % b.size != 0)
	{
		b.head = b.head->prev;
		c_pos--;
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

void	pa_at_start(t_stack *a, t_stack *b, int *c_pos)
{
	while (*c_pos % b->size != 0)
	{
		inst_rr(b);
		(*c_pos)--;
	}
	inst_pa(a, b);
}

void	pa_at_middle(t_stack *a, t_stack *b, int *c_pos, int middle, int start)
{
	while (*c_pos % b->size != middle - start)
	{
		inst_r(b);
		(*c_pos)++;
	}
	inst_pa(a, b);
}
